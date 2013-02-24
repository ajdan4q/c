#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
/* used to call syscall */
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/syscall.h>
#include <errno.h>

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

static int value;
/* pthread_mutex statically init */
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static pthread_mutex_t mutex;

struct tinfo { /* struct static ? */
	pthread_t tid;
	int tnum;
};

void *add (void *args)
{
	int v;	/* local var in multithreaded-env how? */
	struct tinfo *tf = (struct tinfo *) args;
	tf->tnum = syscall(SYS_gettid); /* syscall gettid */
	while (1)
	{
		v = pthread_mutex_lock(&mutex);
		if (v != 0) handle_error("pthread_mutex_lock");

		if (value >= 100)
		{
			v = pthread_mutex_unlock(&mutex);
			if (v != 0) handle_error("mutex unlock");
			pthread_exit(NULL);
		}

		value += 1;
		debug("thread %d %d", tf->tnum, value);

		v = pthread_mutex_unlock(&mutex);
		if (v != 0) handle_error("mutex unlock");

		//sleep(1);
		usleep(1000);
	}
}

int main (void)
{
	int tc, status;
	tc = 2;

	struct tinfo *tp = malloc(sizeof(struct tinfo) * tc);
	if (tp == NULL) handle_error("malloc");

	status = pthread_mutex_init(&mutex, NULL);
	if (status != 0) handle_error("metex init");

	// start two thread incr 'value'
	int i;
	for (i = 0; i < tc; i++)
	{
		//tp[i].tnum = i; /* set app-specific tid */
		status = pthread_create(&tp[i].tid, NULL, add, &tp[i]);
		if (status != 0) handle_error("pthread create");
	}

	//pause();

	// join thread
	for (i = 0; i < tc; i++)
	{
		status = pthread_join(tp[i].tid, NULL);
		if (status != 0) handle_error("pthread_join");
	}

	status = pthread_mutex_destroy(&mutex);
	if (status != 0) handle_error("mutex destroy");

	free(tp);

	return 0;
}
