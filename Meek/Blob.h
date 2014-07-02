// Zheng Yang 2014

#pragma once

#include "Object.h"
#include "ObjectDatabase.h"
#include "ObjectID.h"
#include "Repository.h"

namespace MeekCore
{
	class Blob
	{
	public:
		Blob();
		~Blob();

		Blob *lookup(const unsigned char *sha1);

		int createFromPaths(
			ObjectID *out_oid,
			Stat *out_st,
			Repository *repo,
			const char *full_path,
			bool apply_filters);


	private:
		Object object;
		ObjectDatabase *objectDatabase;
	};

};