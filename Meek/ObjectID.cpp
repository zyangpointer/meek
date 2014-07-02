#include "ObjectID.h"

namespace MeekCore
{

	ObjectID::ObjectID()
	{
	}


	ObjectID::~ObjectID()
	{

	}

	char* ObjectID::toString(char *out, size_t n)
	{
		if (!out || n == 0)
			return "";

		if (n > MEEK_OID_HEXSZ + 1)
			n = MEEK_OID_HEXSZ + 1;

		formatIDString(out, n - 1); // Reserve room for terminating NUL 
		out[n - 1] = '\0';

		return out;
	}

	void ObjectID::formatIDString(char *str, size_t n)
	{
		size_t i, max_i;

		if (n > MEEK_OID_RAWSZ) {
			memset(&str[MEEK_OID_HEXSZ], 0, n - MEEK_OID_HEXSZ);
			n = MEEK_OID_HEXSZ;
		}

		max_i = n / 2;

		for (i = 0; i < max_i; i++)
			str = formatIDChar(str, this->id[i]);

		if (n & 1)
			*str++ = HEX[this->id[i] >> 4];
	}

	MEEK_INLINE(char) * ObjectID::formatIDChar(char *str, unsigned int val)
	{
		*str++ = HEX[val >> 4];
		*str++ = HEX[val & 0xf];
		return str;
	}
}


