#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

// key is not NULL, invoked and pass key's value to args
void destructor (void *args)
{
	printf("destructor called, args is %d\n", (int *) args);
}

void pcleanup (void *args)
{
	printf("pthread cleanup called %d\n", (int *) args);
}

static pthread_key_t key;
static pthread_once_t once_control = PTHREAD_ONCE_INIT;

void key_init (void)
{
	pthread_key_create(&key, destructor);
	printf("pthread_once control executed only once\n");
}

void *worker (void *args)
{
	pthread_once(&once_control, key_init);

	int tid = syscall(SYS_gettid);
	pthread_cleanup_push(pcleanup, (int *)tid);

	pthread_setspecific(key, (int *)tid);
	printf("thread tid %d\n", tid);

	pthread_cleanup_pop(1);
	pthread_exit(NULL);
}

int main (void)
{
	pthread_attr_t pthread_attr;
	pthread_attr_init(&pthread_attr);
	//pthread_attr_setdetachstate(&pthread_attr, PTHREAD_CREATE_DETACHED);

	printf("main thread tid %ld\n", syscall(SYS_gettid));

	const int max_thread = 4;
	pthread_t tinfo[max_thread];

	int i;
	for (i = 0; i < max_thread; i++)
	{
		pthread_create(&tinfo[i], &pthread_attr,
				worker, NULL);
	}

	for (i = 0; i < max_thread; i++)
		pthread_join(tinfo[i], NULL);

	pthread_key_delete(key);
	pthread_attr_destroy(&pthread_attr);

	return EXIT_SUCCESS;
}
