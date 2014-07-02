#include "Buffer.h"
#include "Utils.h"

namespace MeekCore
{
	Buffer::Buffer()
	{
		this->ptr = InitialBuffer;
		asize = 0;
		size = 0;

	}
	
	Buffer::~Buffer()
	{
		if (this->ptr)
		{
			delete ptr;
			ptr = NULL;
		}
	}

	void Buffer::init(size_t initial_size)
	{
		this->asize = 0;
		this->size = 0;
		this->ptr = InitialBuffer;

		if (initial_size)
			growBuffer(initial_size);
	}

	int Buffer::growBuffer(size_t target_size)
	{
		return tryGrowBuffer(target_size, true, true);
	}

	int Buffer::tryGrowBuffer(
		size_t target_size, bool mark_oom, bool preserve_external)
	{
		char *new_ptr;
		size_t new_size;

		if (this->ptr == BufferCom)
			return -1;

		if (!target_size)
			target_size = size;

		if (target_size <= asize)
			return 0;

		if (asize == 0) {
			new_size = target_size;
			new_ptr = NULL;
		}
		else {
			new_size = asize;
			new_ptr = ptr;
		}

		/* grow the buffer size by 1.5, until it's big enough
		* to fit our target size */
		while (new_size < target_size)
			new_size = (new_size << 1) - (new_size >> 1);

		/* round allocation up to multiple of 8 */
		new_size = (new_size + 7) & ~7;

		new_ptr = (char *)MeekUtils::MeekRealloc(new_ptr, new_size);

		if (!new_ptr) {
			if (mark_oom) {
				if (ptr) free(ptr);
				ptr = BufferCom;
			}
			return -1;
		}

		if (preserve_external && !asize && ptr != NULL && size > 0)
			memcpy(new_ptr, ptr, min(size, new_size));

		asize = new_size;
		ptr = new_ptr;

		/* truncate the existing buffer size if necessary */
		if (size >= asize)
			size = asize - 1;
		ptr[size] = '\0';

		return 0;
	}

	MEEK_INLINE(int) Buffer::joinPath(Buffer *buffer, const char *a, const char *b)
	{
		//return joinBuffer(buffer, '/', a, b);
	}

	int Buffer::joinBuffer(char separator, const char *str_a, const char *str_b)
	{
		size_t strlen_a = str_a ? strlen(str_a) : 0;
		size_t strlen_b = strlen(str_b);
		int need_sep = 0;
		size_t offset_a = -1;

		/* not safe to have str_b point internally to the buffer */
		assert(str_b < ptr || str_b >= ptr + size);

		/* figure out if we need to insert a separator */
		if (separator && strlen_a) {
			while (*str_b == separator) { str_b++; strlen_b--; }
			if (str_a[strlen_a - 1] != separator)
				need_sep = 1;
		}

		/* str_a could be part of the buffer */
		if (str_a >= ptr && str_a < ptr + size)
			offset_a = str_a - ptr;

		if (growBuffer(strlen_a + strlen_b + need_sep + 1) < 0)
			return -1;
		assert(ptr);

		/* fix up internal pointers */
		if (offset_a >= 0)
			str_a = ptr + offset_a;

		/* do the actual copying */
		if (offset_a != 0 && str_a)
			memmove(ptr, str_a, strlen_a);
		if (need_sep)
			ptr[strlen_a] = separator;

		memcpy(ptr + strlen_a + need_sep, str_b, strlen_b);

		size = strlen_a + strlen_b + need_sep;
		ptr[size] = '\0';

		return 0;
	}
}


