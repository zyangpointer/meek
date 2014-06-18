#include "Buffer.h"

namespace MeekCore
{

	Buffer::Buffer()
	{
	}


	Buffer::~Buffer()
	{
		if (this->ptr)
		{
			delete ptr;
			ptr = NULL;
		}
			
	}

	MEEK_INLINE(int) Buffer::joinPath(Buffer *buffer, const char *a, const char *b)
	{
		return joinBuffer(buffer, '/', a, b);
	}

	int Buffer::joinBuffer(Buffer *buf, char separator, const char *str_a, const char *str_b)
	{
		size_t strlen_a = str_a ? strlen(str_a) : 0;
		size_t strlen_b = strlen(str_b);
		int need_sep = 0;
		size_t offset_a = -1;

		/* not safe to have str_b point internally to the buffer */
		assert(str_b < buf->ptr || str_b >= buf->ptr + buf->size);

		/* figure out if we need to insert a separator */
		if (separator && strlen_a) {
			while (*str_b == separator) { str_b++; strlen_b--; }
			if (str_a[strlen_a - 1] != separator)
				need_sep = 1;
		}

		/* str_a could be part of the buffer */
		if (str_a >= buf->ptr && str_a < buf->ptr + buf->size)
			offset_a = str_a - buf->ptr;

		/*if (git_buf_grow(buf, strlen_a + strlen_b + need_sep + 1) < 0)
		return -1;
		assert(buf->ptr);*/

		/* fix up internal pointers */
		if (offset_a >= 0)
			str_a = buf->ptr + offset_a;

		/* do the actual copying */
		if (offset_a != 0 && str_a)
			memmove(buf->ptr, str_a, strlen_a);
		if (need_sep)
			buf->ptr[strlen_a] = separator;
		memcpy(buf->ptr + strlen_a + need_sep, str_b, strlen_b);

		buf->size = strlen_a + strlen_b + need_sep;
		buf->ptr[buf->size] = '\0';

		return 0;
	}

}


