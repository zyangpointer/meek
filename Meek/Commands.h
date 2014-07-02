#pragma once
#include "ObjectDatabase.h"
#include "Posix.h"
#include "FileUtils.h"

using namespace MeekCore;
using namespace MeekUtils::PosixUtils;
using namespace MeekUtils::FileUtils;

namespace MeekCommands
{
	static int Command_Commit(int argc, const char **argv, const char *prefix) 
	{
		return 0;
	}

	static int Command_Init(int argc, const char **argv, const char *prefix)
	{
		//ObjectDatabase::initDirectory("D:/meektest", "", 0);
		FileUtils::mkfile("D:/gittest2/file.txt", "content");
		FileUtils::mkfile("D:/gittest2/file1.txt", "Hello World");

		// make file with oid


		return 1;
	}

	static int Command_Add(int argc, const char **argv, const char *prefix)
	{
		return 0;
	}

	static int cmd_help(int argc, const char **argv, const char *prefix)
	{
		return 0;
	}
}
