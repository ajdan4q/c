/* use single thread to read /proc/uptime */
#include <pthread.h> /* pthread support */
#include <stdio.h> /* get perror */
#include <stdlib.h>
#include <string.h> /* get strdup */
#include <errno.h> /* intro errno */
#include "dbg.h"
/* intro getpid */
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#define _GNU_SOURCE


#define handle_error_en(en, msg) \
	do { errno=en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

typedef struct info {
	float total_time;
	float idle_time;
} Info;

void print_pid_tid(char *msg)
{
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s getpid() %u pthread_self() %u %#x ", msg,
		(unsigned int) pid, (unsigned int) tid, (unsigned int) tid);
	pid = syscall(SYS_getpid);
	tid = syscall(SYS_gettid);
	printf("sys_getpid %u, sys_gettid %u\n",
			(unsigned int) pid, (unsigned int) tid);
}

static void *worker (void *args);

int main (void)
{
	int en;
	pthread_t tid;

	Info *msg = malloc(sizeof(Info));
	if (msg == NULL) handle_error("malloc");

	void *exit_value;

	// new thread
	en = pthread_create(&tid, NULL, worker, msg);
	if (en != 0) handle_error_en(en, "pthread_create");

	print_pid_tid("main thread");

	// wait finish, get pthread return value
	en = pthread_join(tid, &exit_value);
	if (en != 0) handle_error_en(en, "pthread_join");

	printf("thread exit value %s\n", (char *) exit_value);

	// print result
	printf("total time %.2f, idle time %.2f\n",
			msg->total_time, msg->idle_time);

	en = pthread_detach(pthread_self());
	if (en != 0) handle_error_en(en, "pthread_detach");

	free(exit_value);
	free(msg);

	exit(EXIT_SUCCESS);
}

/* cleanup function will be called
 * 1 thread cancellation
 * 2 pthread_exit invoke
 * 3 pthread_cleanup_pop(1)
 */
void pcleanup(void *args)
{
	printf("pthread cleanup called\n");
}

static void *worker (void *args)
{
	print_pid_tid("new thread ");
	Info *msg = (Info *) args;
	if (msg == NULL) handle_error("args");

	int c;
	char *status = strdup("test");
	if (status == NULL) handle_error("strdup");

	pthread_cleanup_push(pcleanup, NULL);

	FILE *f = fopen("/proc/uptime", "r");
	if (f == NULL) handle_error("fopen");

	c = fscanf(f, "%f %f", &msg->total_time, &msg->idle_time);
	if ( c != 2) handle_error_en(c, "fscanf");

	int en;
	en = fclose(f);
	if (en != 0) handle_error_en(en, "fclose");

	/*pthread_exit((int *)9);*/
	/*return 0;*/
	/*return (void *) 9;*/
	/*return NULL;*/

	return status; // cleanup not called
	//pthread_exit(status); // cleanup called
	pthread_cleanup_pop(1); // cleanup called
}
