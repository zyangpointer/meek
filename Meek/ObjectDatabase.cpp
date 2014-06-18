#include "ObjectDatabase.h"
#include <direct.h>
#include "Utils.h"
#include "Buffer.h"

using namespace MeekUtils;

namespace MeekCore
{

	ObjectDatabase::ObjectDatabase()
	{
	}


	ObjectDatabase::~ObjectDatabase()
	{
	}

	int ObjectDatabase::init()
	{
		
		return 1;
	}

	int ObjectDatabase::commit()
	{
		return 0;
	}

	int ObjectDatabase::initDirectory(const char *repo_path, const char *wd_path,
		const char *given_repo)
	{
		/*int error = 0;
		bool isBare, addDotMeek, hasDotMeek, naturalWd;

		addDotMeek =
			(compareSuffix(given_repo, "/" DOT_MEEK) != 0 &&
			 compareSuffix(given_repo, "/" MEEK_DIR) != 0);*/

		/*if (Buffer::joinPath(repo_path, given_repo, addDotMeek ? MEEK_DIR : "") < 0)
			return -1;*/
		
		_mkdir("D:/gittest2/");
		_mkdir("D:/gittest2/.git");
		_mkdir("D:/gittest2/.git/objects");
		_mkdir("D:/gittest2/.git/info");
		_mkdir("D:/gittest2/.git/hooks");
		_mkdir("D:/gittest2/.git/refs");

		return 1;
	}

	int ObjectDatabase::write()
	{
		// Write to file on disk. 
		return 0;
	}

}
