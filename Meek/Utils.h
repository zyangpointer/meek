// Zheng Yan 2014

#pragma once
#include "common.h"
#include <stdio.h>
#include <ctype.h>

#include "common.h"
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include "MSVC-Compat.h"

#ifdef _MSC_VER
# include <Shlwapi.h>
#endif

namespace MeekUtils
{
	static int compareSuffix(const char *str, const char *suffix)
	{
		size_t a = strlen(str);
		size_t b = strlen(suffix);

		if (a < b)
			return -1;

		return strcmp(str + (a - b), suffix);
	}


	static  MEEK_INLINE(void *) MeekRealloc(void *ptr, size_t size)
	{
		void *new_ptr = realloc(ptr, size);
		//if (!new_ptr) 
		assert(new_ptr);
		return new_ptr;
	}


	static int meek_strcmp(const char *a, const char *b)
	{
		while (*a && *b && *a == *b)
			++a, ++b;
		return (int)(*(const unsigned char *)a) - (int)(*(const unsigned char *)b);
	}

	static int meek_strcasecmp(const char *a, const char *b)
	{
		while (*a && *b && tolower(*a) == tolower(*b))
			++a, ++b;
		return (tolower(*a) - tolower(*b));
	}

	static int meek_strcasesort_cmp(const char *a, const char *b)
	{
		int cmp = 0;

		while (*a && *b)
		{
			if (*a != *b)
			{
				if (tolower(*a) != tolower(*b))
					break;
				// use case in sort order even if not in equivalence
				if (!cmp)
					cmp = (int)(*(const uint8_t *)a) - (int)(*(const uint8_t *)b);
			}

			++a, ++b;
		}

		if (*a || *b)
			return tolower(*a) - tolower(*b);

		return cmp;
	}

	static int meek_strncmp(const char *a, const char *b, size_t sz)
	{
		while (sz && *a && *b && *a == *b)
			--sz, ++a, ++b;
		if (!sz)
			return 0;
		return (int)(*(const unsigned char *)a) - (int)(*(const unsigned char *)b);
	}

	static int meek_strncasecmp(const char *a, const char *b, size_t sz)
	{
		int al, bl;

		do {
			al = (unsigned char)tolower(*a);
			bl = (unsigned char)tolower(*b);
			++a, ++b;
		} while (--sz && al && al == bl);

		return al - bl;
	}

	static void meek_strntolower(char *str, size_t len)
	{
		size_t i;

		for (i = 0; i < len; ++i) {
			str[i] = (char)tolower(str[i]);
		}
	}

	static void meek_strtolower(char *str)
	{
		meek_strntolower(str, strlen(str));
	}

	static int meek_prefixcmp(const char *str, const char *prefix)
	{
		for (;;) {
			unsigned char p = *(prefix++), s;
			if (!p)
				return 0;
			if ((s = *(str++)) != p)
				return s - p;
		}
	}

	static int meek_prefixcmp_icase(const char *str, const char *prefix)
	{
		return strncasecmp(str, prefix, strlen(prefix));
	}

	static int meek_suffixcmp(const char *str, const char *suffix)
	{
		size_t a = strlen(str);
		size_t b = strlen(suffix);
		if (a < b)
			return -1;
		return strcmp(str + (a - b), suffix);
	}

	static char *meek_strtok(char **end, const char *sep)
	{
		char *ptr = *end;

		while (*ptr && strchr(sep, *ptr))
			++ptr;

		if (*ptr) {
			char *start = ptr;
			*end = start + 1;

			while (**end && !strchr(sep, **end))
				++*end;

			if (**end) {
				**end = '\0';
				++*end;
			}

			return start;
		}

		return NULL;
	}

	/* Similar to strtok, but does not collapse repeated tokens. */
	static char *meek_strsep(char **end, const char *sep)
	{
		char *start = *end, *ptr = *end;

		while (*ptr && !strchr(sep, *ptr))
			++ptr;

		if (*ptr) {
			*end = ptr + 1;
			*ptr = '\0';

			return start;
		}

		return NULL;
	}

	static void meek_hexdump(const char *buffer, size_t len)
	{
		static const size_t LINE_WIDTH = 16;

		size_t line_count, last_line, i, j;
		const char *line;

		line_count = (len / LINE_WIDTH);
		last_line = (len % LINE_WIDTH);

		for (i = 0; i < line_count; ++i) {
			line = buffer + (i * LINE_WIDTH);
			for (j = 0; j < LINE_WIDTH; ++j, ++line)
				printf("%02X ", (unsigned char)*line & 0xFF);

			printf("| ");

			line = buffer + (i * LINE_WIDTH);
			for (j = 0; j < LINE_WIDTH; ++j, ++line)
				printf("%c", (*line >= 32 && *line <= 126) ? *line : '.');

			printf("\n");
		}

		if (last_line > 0) {

			line = buffer + (line_count * LINE_WIDTH);
			for (j = 0; j < last_line; ++j, ++line)
				printf("%02X ", (unsigned char)*line & 0xFF);

			for (j = 0; j < (LINE_WIDTH - last_line); ++j)
				printf("	");

			printf("| ");

			line = buffer + (line_count * LINE_WIDTH);
			for (j = 0; j < last_line; ++j, ++line)
				printf("%c", (*line >= 32 && *line <= 126) ? *line : '.');

			printf("\n");
		}

		printf("\n");
	}

	/**
	* A strcmp wrapper
	*
	* We don't want direct pointers to the CRT on Windows, we may
	* get stdcall conflicts.
	*/
	static int meek_strcmp_cb(const void *a, const void *b)
	{
		return strcmp((const char *)a, (const char *)b);
	}

	static int meek_strcasecmp_cb(const void *a, const void *b)
	{
		return strcasecmp((const char *)a, (const char *)b);
	}

	static int meek_parse_bool(int *out, const char *value)
	{
		/* A missing value means true */
		if (value == NULL ||
			!strcasecmp(value, "true") ||
			!strcasecmp(value, "yes") ||
			!strcasecmp(value, "on")) {
			*out = 1;
			return 0;
		}
		if (!strcasecmp(value, "false") ||
			!strcasecmp(value, "no") ||
			!strcasecmp(value, "off") ||
			value[0] == '\0') {
			*out = 0;
			return 0;
		}

		return -1;
	}

	static size_t meek_unescape(char *str)
	{
		char *scan, *pos = str;

		if (!str)
			return 0;

		for (scan = str; *scan; pos++, scan++) {
			if (*scan == '\\' && *(scan + 1) != '\0')
				scan++; /* skip '\' but include next char */
			if (pos != scan)
				*pos = *scan;
		}

		if (pos != scan) {
			*pos = '\0';
		}

		return (pos - str);
	}

}
