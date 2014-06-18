// Zheng Yang 2014

#pragma

#if (defined(_WIN32)) && !defined(__CYGWIN__)
#define MEEK_WIN32 1
#endif

// Declare a function as always inlined.
#if defined(_MSC_VER)
# define MEEK_INLINE(type) __inline type
#else
# define MEEK_INLINE(type) inline type
#endif

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#ifdef MEEK_WIN32

# include <io.h>
# include <direct.h>
# include <winsock2.h>
# include <windows.h>
//# include "win32/msvc-compat.h"
//# include "win32/mingw-compat.h"
//# include "win32/error.h"
//# include "win32/version.h"
# ifdef MEEK_THREADS
#	include "win32/pthread.h"
# endif

#else

# include <string.h>
# ifdef MEEK_THREADS
#	include <pthread.h>
#	include <sched.h>
# endif
#define MEEK_STDLIB_CALL

#endif

#ifdef __cplusplus
# define MEEK_BEGIN_DECL extern "C" {
# define MEEK_END_DECL	}
#else
// Start declarations in C mode 
# define MEEK_BEGIN_DECL /* empty */
// End declarations in C mode */
# define MEEK_END_DECL	/* empty */
#endif

// Declare a public function exported for application use. 
#if __GNUC__ >= 4
# define MEEK_EXTERN(type) extern \
	__attribute__((visibility("default"))) \
	type
#elif defined(_MSC_VER)
# define MEEK_EXTERN(type) __declspec(dllexport) type
#else
# define MEEK_EXTERN(type) extern type
#endif

// Declare a function's takes printf style arguments. */
#ifdef __GNUC__
# define MEEK_FORMAT_PRINTF(a,b) __attribute__((format (printf, a, b)))
#else
# define MEEK_FORMAT_PRINTF(a,b) /* empty */
#endif



