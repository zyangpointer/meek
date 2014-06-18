// Zheng Yang 2014

#pragma once

#include <sys/types.h>
#ifdef __amigaos4__
#include <stdint.h>
#endif

#if defined(_MSC_VER)

typedef __int64 MeekInt64;
typedef __time64_t MeekTime;

#elif defined(__MINGW32__)

typedef off64_t MeekInt64;
typedef __time64_t MeekTime;

#endif

/** Basic type (loose or packed) of any Git object. */
enum MeekType{
	MEEK_OBJ_COMMIT = 1,	/**< A commit object. */
	MEEK_OBJ_TREE = 2,		/**< A tree (directory listing) object. */
	MEEK_OBJ_BLOB = 3,		/**< A file revision object. */
	MEEK_OBJ_TAG = 4,		/**< An annotated tag object. */
};