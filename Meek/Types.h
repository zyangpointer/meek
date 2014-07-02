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
	MEEK_OBJ_COMMIT = 1,	// A commit object. 
	MEEK_OBJ_TREE = 2,		// A tree (directory listing) object. 
	MEEK_OBJ_BLOB = 3,		// A file revision object. 
	MEEK_OBJ_TAG = 4,		//  An annotated tag object. 
};


/** struct stat is a system struct that is defined to store information about 
 files. It is used in several system calls, including fstat, lstat, and stat.

 The struct stat is simply a structure with the following fields:

 Field Name	Description
 st_mode	The current permissions on the file.
 st_ino	The inode for the file (note that this number is unique to all files and directories on a Linux System.
 st_dev	The device that the file currently resides on.
 st_uid	The User ID for the file.
 st_gid	The Group ID for the file.
 st_atime	The most recent time that the file was accessed.
 st_ctime	The most recent time that the file's permissions were changed.
 st_mtime	The most recent time that the file's contents were modified.
 st_nlink	The number of links that there are to this file.
 st_size
 **/

typedef struct stat Stat;