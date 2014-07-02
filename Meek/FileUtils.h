//Zheng Yang 2014

#pragma once

namespace MeekUtils
{
	namespace FileUtils
	{
		class FileUtils
		{
		public:
			FileUtils();
			~FileUtils();

			static int mkdir(const char *path, const char *base);
			static int mkfile(const char *filename, const char *content);
		};
	}

}
