#include "Repository.h"

namespace MeekCore
{

	Repository::Repository()
	{
	}


	Repository::~Repository()
	{
	}

	int Repository::init(
		Repository **repout,
		const char *path,
		unsigned is_bare)
	{
		return initExt(repout, path);
	}

	int Repository::initExt(
		Repository **out,
		const char *given_repo)
	{
		int error;

		assert(out && given_repo);
		//initDirectories
		return 1;
	}

	int initDirectories(
		const char *repo_path,
		const char *wd_path,
		const char *given_repo)
	{
		return 1;
	}

}

