//Zheng Yang 2014

#pragma once

#include "Common.h"
#include "Types.h"
//#include "oid.h"
#include "Buffer.h"
#include "Index.h"

namespace MeekCore
{

	class Repository
	{
	public:
		Repository();
		~Repository();

		/**
		* Get the Index file for this repository.
		*
		* If a custom index has not been set, the default
		* index for the repository will be returned (the one
		* located in `.meek/index`).
		*
		* The index must be freed once it's no longer being used by
		* the user.
		**/
		//MEEK_EXTERN(int) getIndexFromRepository(Index **out, Repository **out);
	

		/**
		* Creates a new Git repository in the given folder.
		*/
		MEEK_EXTERN(int) init(
			Repository **out,
			const char *path,
			unsigned is_bare);

		MEEK_EXTERN(int) initExt(Repository **out,
			const char *given_repo);

		int initDirectories(
			const char *repo_path,
			const char *wd_path,
			const char *given_repo);
	};
}

