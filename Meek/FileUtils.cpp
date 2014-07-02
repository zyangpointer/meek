#include "FileUtils.h"
#include "Buffer.h"

#include "Common.h"
#include <ctype.h>

#include "Posix.h"

using namespace MeekCore;
using namespace MeekUtils::PosixUtils;

using namespace MeekCore;

namespace MeekUtils
{
	namespace FileUtils
	{
		FileUtils::FileUtils()
		{
		}


		FileUtils::~FileUtils()
		{
		}

		int FileUtils::mkdir(const char *path, const char *base)
		{
			Buffer make_path;
			strcmp(make_path.ptr, path);
			
			// Make directory
			_mkdir(make_path.ptr);


			return 1;
		}

		int FileUtils::mkfile(const char *filename, const char *content)
		{
			int fd = p_creat(filename, 0666);

			assert(fd != 0);

			p_write(fd, content, strlen(content));

			return 1;
		}
	}

}