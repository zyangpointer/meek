// Zheng Yang 2014
#pragma once

#include "Common.h"

/* Used as default value for git_buf->ptr so that people can always
* assume ptr is non-NULL and zero terminated even for new git_bufs.
*/


namespace MeekCore
{
	class Buffer
	{
	public:
		Buffer();
		~Buffer();

	public:
		static MEEK_INLINE(int) joinPath(Buffer *buffer, const char *a, const char *b);

	
		int joinBuffer(Buffer *buf, char separator, const char *str_a, const char *str_b);
		void init(size_t initial_size);

		int growBuffer(size_t target_size);
		int tryGrowBuffer(size_t target_size, bool mark_oom, bool preserve_external);
		
		char   *ptr;
		size_t asize, size;

		char InitialBuffer[1];
		char BufferCom[1];
	};
}

