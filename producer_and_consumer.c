#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include "dbg.h"
#include <sys/syscall.h>
#define _GNU_SOURCE

#define NPRODUCER 2
#define NCONSUMER 2
#define RES_SIZE 100

static pthread_mutex_t mutex;
static pthread_cond_t data;
static pthread_cond_t nodata;
static char *res;
static char *freep;
static FILE *f;

typedef struct tinfo {
	pthread_t tid;
	int tnum;
} Tinfo;

void pcleanup (void *args)
{
	int en;
	en = pthread_mutex_unlock(&mutex);
	assert(en == 0);
}
// stack: LIFO
void push (int num)
{
	assert(freep >= res && freep <= res + RES_SIZE);
	*freep = num;
	freep++;
}

int pop (void)
{
	freep--;
	assert(freep >= res);
	*freep = '\0'; // identify res end
	return *(freep + 1);
}

// queue: FIFO
void enterqueue (int num)
{
	push(num);
}

int outqueue (void)
{
	return 0;
}
void *producer (void *args)
{
	Tinfo *tinfo = (Tinfo *) args;
	tinfo->tnum = syscall(SYS_gettid);

	const int fill_len = 10;
	pthread_cleanup_push(pcleanup, NULL);
	while (1)
	{
		pthread_mutex_lock(&mutex);
		// array res full
		while (freep + fill_len > res + RES_SIZE - 1)
		{
			pthread_cond_wait(&nodata, &mutex);
		}

		//fill_data();
		int i;
		for (i = 0; i < fill_len; i++)
			push('a');
		debug("res content %s", res);

		pthread_cond_signal(&data); // notify next consumer
		pthread_mutex_unlock(&mutex);
	}
	pthread_cleanup_pop(1);
}

void *consumer (void *args)
{
	Tinfo *tinfo = (Tinfo *) args;
	tinfo->tnum = syscall(SYS_gettid);

	const int remove_len = 1;
	pthread_cleanup_push(pcleanup, NULL);
	while (1)
	{
		pthread_mutex_lock(&mutex);
		while (freep - res < remove_len)
		{
			pthread_cond_wait(&data, &mutex);
		}

		//remove_data();
		int i;
		for (i = 0; i < remove_len; i++)
			pop();
		debug("res content %s", res);

		pthread_cond_signal(&nodata); // notify next producer
		pthread_mutex_lock(&mutex);
	}
	pthread_cleanup_pop(1);
}

#define mutexattr_pshared_str(i) \
	((i) == PTHREAD_PROCESS_PRIVATE) ? \
	"PTHREAD_PROCESS_PRIVATE" : "PTHREAD_PROCESS_SHARED"

#define condattr_pshared_str(i) mutexattr_pshared_str(i)

#define pthread_detach_state_str(i) \
	((i) == PTHREAD_CREATE_DETACHED) ? \
	"PTHREAD_CREATE_DETACHED" : "PTHREAD_CREATE_JOINABLE"

#if 0
// FAILURE
const char *mutexattr_protocol_str (int i)
{
	switch (i) {
	case (PTHREAD_PRIO_NONE):
		return "PTHREAD_PRIO_NONE";
	case (PTHREAD_PRIO_INHERIT):
		return "PTHREAD_PRIO_INHERITE";
	case (PTHREAD_PRIO_PROTECT):
		return "PTHREAD_PRIO_PROTECT";
	default:
		return "UNKNOW PROCOCOL";
	}
}
#endif

const char *mutexattr_type_str(int i)
{
	switch (i)
	{
		case PTHREAD_MUTEX_DEFAULT:
			return "PTHREAD_MUTEX_NORMAL/DEFAULT";
		case PTHREAD_MUTEX_ERRORCHECK:
			return "PTHREAD_MUTEX_ERRORCHECK";
		case PTHREAD_MUTEX_RECURSIVE:
			return "PTHREAD_MUETX_RECURSIVE";
		default:
			return "UNKNOW TYPE";
	}
}

int main (void)
{
	int en;
	// resource alloc and init
	res = malloc(RES_SIZE + 1);
	assert(res != NULL);
	memset(res, '\0', RES_SIZE + 1);
	freep = res;

	f = fopen("/dev/urandom", "r"); /* how to use /dev/urandom */
	assert(f != NULL);

	// thread info alloc
	Tinfo *tinfo = malloc(sizeof(Tinfo) * (NPRODUCER + NCONSUMER));
	assert(tinfo != NULL);

	// mutex owner of dead issue
	// NOTE first init mutexattr object, then set/get attr
	// mutexattr init, set/get
	pthread_mutexattr_t mutex_attr;

	pthread_mutexattr_init(&mutex_attr);
	pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_ERRORCHECK);

	// how to print enum string value
	pthread_mutexattr_getpshared(&mutex_attr, &en);
	debug("pthread mutexattr pshared (scope) %s",
			mutexattr_pshared_str(en));

	pthread_mutexattr_gettype(&mutex_attr, &en);
	debug("pthread mutexattr type %s", mutexattr_type_str(en));

	pthread_mutexattr_getprotocol(&mutex_attr, &en);
	debug("pthread mutexattr protocol %d", en);

	pthread_mutexattr_getprioceiling(&mutex_attr, &en);
	debug("pthread mutexattr priority ceiling %d", en);

	// NOTE first mutex object init, then get/set mutex
	// mutex init, get/set
	pthread_mutex_init(&mutex, &mutex_attr);

	pthread_mutex_getprioceiling(&mutex, &en);
	debug("pthread mutex priority ceiling %d", en);

	// condattr init, set/get
	pthread_condattr_t cond_attr;
	pthread_condattr_init(&cond_attr);

	pthread_condattr_getpshared(&cond_attr, &en);
	debug("pthread condattr pshared (scope) %s",
			condattr_pshared_str(en));

	pthread_cond_init(&data, &cond_attr);
	pthread_cond_init(&nodata, &cond_attr);

	// pthread attr init, set/get
	pthread_attr_t pthread_attr;

	pthread_attr_init(&pthread_attr);
	pthread_attr_setdetachstate(&pthread_attr, PTHREAD_CREATE_DETACHED);
	int ds;
	pthread_attr_getdetachstate(&pthread_attr, &ds);
	debug("pthread attr detachstate %s", pthread_detach_state_str(ds));

	// start consumer thread
	int i;
	for (i = 0; i < NCONSUMER; i++)
	{
		en = pthread_create(&tinfo[i].tid, &pthread_attr,
				consumer, &tinfo[i]);
		assert(en == 0);
		debug("start consumer thread %d", i);
		//pthread_detach(tinfo[i].tid);
	}

	// start producer thread, detached
	for (; i < NPRODUCER + NCONSUMER; i++)
	{
		en = pthread_create(&tinfo[i].tid, &pthread_attr,
				producer, &tinfo[i]);
		assert(en == 0);
		debug("start producer thread %d", i);
	}

	sleep(5);

	debug("after sleep some seconds");
	for (i = 0; i < NCONSUMER + NPRODUCER; i++)
	{
		en = pthread_cancel(tinfo[i].tid);
		assert(en == 0);
		debug("cancel thread %d", tinfo[i].tnum);
		/*
		en = pthread_join(tinfo[i].tid, NULL);
		assert(en == 0);
		debug("join thread %d", tinfo[i].tnum);
		*/
	}

	debug("clean opt");
	// clean operate
	pthread_condattr_destroy(&cond_attr);
	pthread_mutexattr_destroy(&mutex_attr);
	pthread_attr_destroy(&pthread_attr);
	pthread_cond_destroy(&data);
	pthread_cond_destroy(&nodata);
	pthread_mutex_destroy(&mutex);

	fclose(f);
	free(res);
	free(tinfo);
	return EXIT_SUCCESS;
}
