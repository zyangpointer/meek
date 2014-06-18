#pragma once
#include "ObjectDatabase.h"

using namespace MeekCore;

namespace MeekCommands
{
	static int Command_Commit(int argc, const char **argv, const char *prefix) 
	{
		return 0;
	}

	static int Command_Init(int argc, const char **argv, const char *prefix)
	{
		ObjectDatabase::initDirectory("D:/meektest", "", 0);
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
