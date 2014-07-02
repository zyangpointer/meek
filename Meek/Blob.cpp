#include "Blob.h"

namespace MeekCore
{

	Blob::Blob()
	{
	}


	Blob::~Blob()
	{
	}

	Blob *lookup(const unsigned char *sha1)
	{
		return 0;
	}

	int Blob::createFromPaths(
		ObjectID *out_oid,
		Stat *out_st,
		Repository *repo,
		const char *content_path,
		bool apply_filters)
	{
		int error;
		struct stat st;
		ObjectDatabase *odb = NULL;
		Buffer path;


		//write_file_stream

		return 1;
	}


}
