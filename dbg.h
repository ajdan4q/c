#ifndef __dbg_h
#define __dbg_h

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) \
	fprintf(stdout, "DEBUG %s %s %d: " M "\n", \
			__FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) \
	fprintf(stderr, "[ERROR] (%s:%s:%d errno: %s) " M "\n", \
		__FILE__, __FUNCTION__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) \
	fprintf(stderr, "[WARN] (%s:%s:%d errno: %s) " M "\n", __FILE__, \
			__FUNCTION__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) \
	fprintf(stdout, "[INFO] (%s:%s:%d) " M "\n", \
			__FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) \
	if (!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) \
	if (!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

// without errno, function set already
#define err_exit(M, ...) \
	{ log_err(M, ##__VA_ARGS__); exit(EXIT_FAILURE); }

#define err_ret(M, ...) \
	{ log_err(M, ##__VA_ARGS__); return(EXIT_FAILURE); }

#define err_abort(M, ...) \
	{ log_err(M, ##__VA_ARGS__); abort(); }

// give a errno
#define err_exit_en(M) \
	{ fprintf(stderr, "[ERROR] (%s:%s:%d) %s\n",\
		__FILE__, __FUNCTION__, __LINE__, strerror(M));\
		exit(EXIT_FAILURE); }

#endif
