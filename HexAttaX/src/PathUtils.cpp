#include "PathUtils.h"

#include <Windows.h>


namespace PathUtils
{
	bool GetExePath(std::string& path)
	{
		char fileName[1024];
		DWORD res = GetModuleFileNameA(NULL, fileName, 1024);
		if (res <= 0)
			return false;

		path = fileName;
		size_t lastSlash = path.find_last_of('\\');
		if (lastSlash != std::string::npos)
		{
			path = path.substr(0, lastSlash + 1);
		}
		return true;
	}
}