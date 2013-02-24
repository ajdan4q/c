#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
/* used to call syscall */
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/syscall.h>
#include <errno.h>

#define MAX 100
#define NDEBUG

#ifndef NDEBUG
#define debug(v, msg)
#else
#define debug(M, ...) \
	fprintf(stderr, "[DEBUG] %s:%s:%d: " M "\n", \
			__FILE__, __FUNCTION__, __LINE__,  ##__VA_ARGS__)
#endif

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)
// TODO RESOLVE MEMORY LEAK
static int value;
/* pthread_mutex statically init */
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct tinfo { /* struct static ? */
	pthread_t tid;
	int tnum;
};

/* thread cleanup function while cancel */
void cleanup (void *args)
{
	// how to know whether unlock
	struct tinfo *tf = (struct tinfo *) args;
	int en;
	debug("thread %d release mutex lock", tf->tnum);
	en = pthread_mutex_unlock(&mutex);
	if (en != 0) handle_error("mutex unlock");
}

void *add (void *args)
{
	int v;	/* local var in multithreaded-env how? */
	struct tinfo *tf = (struct tinfo *) args;
	tf->tnum = syscall(SYS_gettid); /* syscall gettid */
	int lock_flag;

	// pair use of pthread_cleanup_xx
	pthread_cleanup_push(cleanup, tf);

	while (1)
	{
		v = pthread_mutex_lock(&mutex);
		lock_flag = 1;
		if (v != 0) handle_error("pthread_mutex_lock");

		while (value >= MAX)
		{
			debug("thread %d value reach %d", tf->tnum, value);
			// need retest 'value'
			v = pthread_cond_wait(&cond, &mutex);
			if (v != 0) handle_error("mutex unlock");
		}

		value += 1;
		debug("thread %d %d", tf->tnum, value);

		v = pthread_mutex_unlock(&mutex);
		lock_flag = 0;
		if (v != 0) handle_error("mutex unlock");

		//usleep(1000);
	}
	pthread_cleanup_pop(lock_flag);
}

void *zero_value (void *args)
{
	struct tinfo *ti = (struct tinfo *) args;
	ti->tnum = syscall(SYS_gettid);
	int lock_flag;

	pthread_cleanup_push(cleanup, ti);

	while (1)
	{
		int en;
		en = pthread_mutex_lock(&mutex); /* not a cancel pointer */
		lock_flag = 1;
		if (en != 0) handle_error("zero_value mutex_lock");

		if (value >= MAX)
		{
			value = 0;
			debug("thread %d zero value to %d", ti->tnum, value);

			en = pthread_cond_broadcast(&cond);
			if (en != 0) handle_error("zero_value cond broadcast");
			/*en = pthread_cond_signal(&cond);*/
			/*if (en != 0) handle_error("zero_value cond signal");*/
		}

		en = pthread_mutex_unlock(&mutex);
		lock_flag = 0;
		if (en != 0) handle_error("zero_value mutex_unlock");

		sleep(1);
	}
	pthread_cleanup_pop(lock_flag);
}

int main (void)
{
	int tc, status;
	tc = 5;

	struct tinfo *tp = malloc(sizeof(struct tinfo) * (tc+1));
	if (tp == NULL) handle_error("malloc");

	status = pthread_mutex_init(&mutex, NULL);
	if (status != 0) handle_error("metex init");

	// start tc thread incr 'value'
	int i;
	for (i = 0; i < tc; i++)
	{
		//tp[i].tnum = i; /* set app-specific tid */
		status = pthread_create(&tp[i].tid, NULL, add, &tp[i]);
		if (status != 0) handle_error("pthread create");
	}

	// start zero_value thread
	status = pthread_create(&tp[i].tid, NULL, zero_value, &tp[i]);
	if (status != 0) handle_error("pthread_create");

	/*pause();*/
	sleep(2);

	// cancel and join thread
	for (i = 0; i < tc + 1; i++)
	{
		// after cancel thread exit value ?
		status = pthread_cancel(tp[i].tid);
		if (status != 0) handle_error("pthread cancel");
		//debug("pthread cancel %d", tp[i].tnum);

		void *exit_value;
		status = pthread_join(tp[i].tid, &exit_value);
		if (status != 0) handle_error("pthread_join");
		if (exit_value == PTHREAD_CANCELED)
			debug("pthread join %d exit_value is PTHREAD_CANCELED",
					tp[i].tnum);
	}

	status = pthread_cond_destroy(&cond);
	if (status != 0) handle_error("cond destroy");

	status = pthread_mutex_destroy(&mutex);
	// success return non-0
	//if (status != 0) handle_error("mutex destroy");

	free(tp);
	return 0;
}
