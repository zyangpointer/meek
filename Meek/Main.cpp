#include <iostream>
#include <string>
#include "Commands.h"

using namespace std;

const char meek_usage_string[] =
"meek [--version] [--help] [-C <path>] [-c name=value]\n"
"           <command> [<args>]";

static int read_options(const char ***argv, int *argc, int *envchanged)
{

}

struct CommandStruct 
{
	const char *command;
	int(*fn)(int, const char **, const char *);
};


static struct CommandStruct commands[] = 
{
	{ "add", MeekCommands::Command_Add }, 
	{ "init", MeekCommands::Command_Init}, 
	{ "commit", MeekCommands::Command_Commit}
};

int main(int argc, char** argv)
{
	//cout << argv[1] << endl;

	if (argc < 2)
	{
		cout << meek_usage_string << endl;
		return 0;
	}

	if (strcmp(argv[1], "--help") == 0)
	{
		cout << meek_usage_string << endl;
	}
	else if (strcmp(argv[1], "init") == 0)
	{
		cout << "Initiating meek repository..." << endl;
		MeekCommands::Command_Init(0, 0, 0);

		cout << "meek repository created." << endl;
	}
	else if (strcmp(argv[1], "add") == 0)
	{
		cout << "Add file to repository" << endl;
	}
	else if (strcmp(argv[1], "commit") == 0)
	{
		cout << "commit" << endl;
	}
	
	return 1;
}