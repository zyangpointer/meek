// Zheng Yang 2014
#pragma once

#include "Common.h"

namespace MeekCore
{
	class Buffer
	{
	public:
		Buffer();
		~Buffer();

	public:
		static MEEK_INLINE(int) joinPath(Buffer *buffer, const char *a, const char *b);

	private:
		static int joinBuffer(Buffer *buf, char separator, const char *str_a, const char *str_b);
		

	private:
		char   *ptr;
		size_t asize, size;
	};
}

