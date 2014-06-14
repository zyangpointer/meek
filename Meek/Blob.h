#pragma once

namespace MeekCore
{
	class Blob
	{
	public:
		Blob();
		~Blob();

		Blob *lookup(const unsigned char *sha1);

	};





};