// Zheng Yan 2014

#pragma once
#include "common.h"
#include <stdio.h>
#include <ctype.h>

namespace MeekUtils
{
	int compareSuffix(const char *str, const char *suffix)
	{
		size_t a = strlen(str);
		size_t b = strlen(suffix);

		if (a < b)
			return -1;

		return strcmp(str + (a - b), suffix);
	}

};