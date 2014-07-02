//Zheng Yang 2014

#pragma once
#include "Common.h"
#include "Types.h"

namespace MeekCore
{
	
	static char HEX[] = "0123456789abcdef";

	class ObjectID
	{
	public:
		ObjectID();
		~ObjectID();

		
		const unsigned int MEEK_OID_RAWSZ = 20;				  // Size (in bytes) of a raw/binary oid
		const unsigned MEEK_OID_HEXSZ = MEEK_OID_RAWSZ * 2; // Size (in bytes) of a hex formatted oid
		static const unsigned int OID_SIZE = 20;				  // Size (in bytes) of a raw/binary oid 

		char *toString(char *out, size_t n);
		void formatIDString(char *str, size_t n);
		MEEK_INLINE(char) *formatIDChar(char *str, unsigned int val);
		


	public:
		
		// Unique identity of any object (commit, tree, blob, tag). 
		unsigned char id[OID_SIZE];
	};

}

