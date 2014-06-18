//Zheng Yang 2014

#pragma once

#include "Buffer.h"
#include "types.h"

#define DOT_MEEK ".meek"
#define MEEK_DIR DOT_MEEK "/"
//#define MEEK_DIR_MODE 0755
//#define MEEK_BARE_DIR_MODE 0777

#define MEEK_OBJECTS_DIR "objects/"
#define MEEK_OBJECT_DIR_MODE 0777
#define MEEK_OBJECT_FILE_MODE 0444

class Buffer;

namespace MeekCore
{
	class ObjectDatabase
	{
	public:
		ObjectDatabase();
		~ObjectDatabase();

	public: 
		static int init();
		static int add();
		static int commit();

		/**
		* Write an object directly into the ObjectDatabase
		*
		* This method writes a full object straight into the ODB.
		* For most cases, it is preferred to write objects through a write
		* stream, which is both faster and less memory intensive, specially
		* for big objects.
		*
		* This method is provided for compatibility with custom backends
		* which are not able to support streaming writes
		*
		* @param out pointer to store the OID result of the write
		* @param odb object database where to store the object
		* @param data buffer with the data to store
		* @param len size of the buffer
		* @param type type of the data to store
		* @return 0 or an error code
		*/
		static int write();

		static int initDirectory(const char *repo_path, const char *wd_path,
			const char *given_repo);
	};

}

