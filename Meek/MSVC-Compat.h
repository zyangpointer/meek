#pragma once

#if defined(_MSC_VER)

// access() mode parameter #defines	
#	define F_OK 0 /* existence check */
#	define W_OK 2 /* write mode check */
#	define R_OK 4 /* read mode check */

#	define lseek _lseeki64
#	define stat _stat64
#	define fstat _fstat64

//  stat: file mode type testing macros 
#	define _S_IFLNK 0120000
#	define S_IFLNK _S_IFLNK
#	define S_IXUSR 00100

#	define S_ISDIR(m)	(((m) & _S_IFMT) == _S_IFDIR)
#	define S_ISREG(m)	(((m) & _S_IFMT) == _S_IFREG)
#	define S_ISFIFO(m) (((m) & _S_IFMT) == _S_IFIFO)
#	define S_ISLNK(m) (((m) & _S_IFMT) == _S_IFLNK)

#	define ModeType unsigned short

//  case-insensitive string comparison
#	define strcasecmp	_stricmp
#	define strncasecmp _strnicmp

//  MSVC doesn't define ssize_t at all 
typedef SSIZE_T ssize_t;

// define snprintf using variadic macro support if available 
#if _MSC_VER >= 1400
# define snprintf(BUF, SZ, FMT, ...) _snprintf_s(BUF, SZ, _TRUNCATE, FMT, __VA_ARGS__)
#else
# define snprintf _snprintf
#endif

#endif

#define MEEK_STDLIB_CALL __cdecl


