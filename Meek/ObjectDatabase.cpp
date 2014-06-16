#include "ObjectDatabase.h"
#include <direct.h>

namespace MeekCore
{

	ObjectDatabase::ObjectDatabase()
	{
	}


	ObjectDatabase::~ObjectDatabase()
	{
	}

	int ObjectDatabase::Init()
	{
		_mkdir("D:/MeekProject/TestProject");
		_mkdir("D:/MeekProject/TestProject/refs/");
		_mkdir("D:/MeekProject/TestProject/refs/heads");
		_mkdir("D:/MeekProject/TestProject/refs/tags");
		_mkdir("D:/MeekProject/TestProject/logs");

		return 1;
	}

	int ObjectDatabase::Commit()
	{
		return 0;
	}

}
