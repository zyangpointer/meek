#pragma once

#include "Common.h"
#include "Buffer.h"
#//include "Vector.h"

/**
* Path manipulation utils
*/

namespace MeekUtils
{
	namespace PathUtils
	{
		/*
		* The dirname() function shall take a pointer to a character string
		* that contains a pathname, and return a pointer to a string that is a
		* pathname of the parent directory of that file. Trailing '/' characters
		* in the path are not counted as part of the path.
		*
		* If path does not contain a '/', then dirname() shall return a pointer to
		* the string ".". If path is a null pointer or points to an empty string,
		* dirname() shall return a pointer to the string "." .
		*
		* The `meek_path_dirname` implementation is thread safe. The returned
		* string must be manually free'd.
		*
		* The `meek_path_dirname_r` implementation writes the dirname to a `Buffer`
		* if the buffer pointer is not NULL.
		* It returns an error code < 0 if there is an allocation error, otherwise
		* the length of the dirname (which will be > 0).
		*/
		static char *meek_path_dirname(const char *path);
		static int meek_path_dirname_r(Buffer *buffer, const char *path);
	}
}
