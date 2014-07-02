// Zheng Yang  2014
#pragma once

#include "Common.h"
#include <errno.h>
#include <io.h>
#include <fcntl.h>
#include <ws2tcpip.h>
#include <share.h>
#include "MSVC-Compat.h"


/* Determine whether an errno value indicates that a read or write failed
* because the descriptor is blocked.
*/
#if defined(EWOULDBLOCK)
#define MEEK_ISBLOCKED(e) ((e) == EAGAIN || (e) == EWOULDBLOCK)
#else
#define MEEK_ISBLOCKED(e) ((e) == EAGAIN)
#endif

#define WIN_PATH_UTF16		260

/* Options which we always provide to _wopen.
*
* _O_BINARY - Raw access; no translation of CR or LF characters
* _O_NOINHERIT - Do not mark the created handle as inheritable by child processes.
*    The Windows default is 'not inheritable', but the CRT's default (following
*    POSIX convention) is 'inheritable'. We have no desire for our handles to be
*    inheritable on Windows, so specify the flag to get default behavior back. */
#define STANDARD_OPEN_FLAGS (_O_BINARY | _O_NOINHERIT)
typedef wchar_t Win32Path[WIN_PATH_UTF16];



namespace MeekUtils
{
	namespace PosixUtils
	{

		static int p_write(int fd, const char *buf, size_t cnt)
		{
			while (cnt) {
				ssize_t r;
#ifdef MEEK_WIN32
				assert((size_t)((unsigned int)cnt) == cnt);
				r = _write(fd, buf, (unsigned int)cnt);
#else
				r = _write(fd, b, cnt);
#endif
				if (r < 0) {
					if (errno == EINTR || MEEK_ISBLOCKED(errno))
						continue;
					return -1;
				}
				if (!r) {
					errno = EPIPE;
					return -1;
				}
				cnt -= r;
				buf += r;
			}
			return 0;
		}

		static int p_creat(const char *path, ModeType mode)
		{
			int fileHandle = 0;

			return _open( path, _O_WRONLY | _O_CREAT | _O_TRUNC | STANDARD_OPEN_FLAGS,  mode);
		}

		static int p_rename(const char *from, const char *to)
		{
			Win32Path wfrom;
			Win32Path wto;
			int rename_tries;
			int rename_succeeded;
			int error;

			// Wait up to 50ms if file is being used 
			rename_tries = 0;
			rename_succeeded = 0;
			while (rename_tries < 10) {
				if (MoveFileExW(wfrom, wto, MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED) != 0) {
					rename_succeeded = 1;
					break;
				}

				error = GetLastError();
				if (error == ERROR_SHARING_VIOLATION || error == ERROR_ACCESS_DENIED) {
					Sleep(5);
					rename_tries++;
				}
				else
					break;
			}

			return rename_succeeded ? 0 : -1;
		}

		static int p_unlink(const char *path)
		{
			Win32Path buf;
			int error;

		
			error = _wunlink(buf);

			// If the file is read-only, clear the access control and do again
			if (error == -1 && errno == EACCES) {
				_wchmod(buf, 0666);
				error = _wunlink(buf);
			}

			return error;
		}

	}
}