#pragma once

#include "Main.h"

namespace Files
{
	class File
	{
	public:
		static std::string DirFile ( const char* Name );

		static char* IniRead ( char *FileName, char *Section, char *Key, char *Default );

		static int ReadInt ( char* Section, char* Key, int Default, char* Patch );
		static int ReadString ( char* Section, char* Key, char* Default, char* Patch );
		static int CharToKey ( char* Key );

		static bool FileExists ( const char *FileName );
	};

	extern File g_File;
}