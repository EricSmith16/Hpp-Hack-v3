#pragma once

#include "Main.h"

#pragma warning (disable: 4244)

namespace Files
{
	class File
	{
	public:
		std::string DirFile ( const char *FileName );

		char *ReadString ( char *Path, char *Section, char *Key, char *DefString )
		{
			char *out = new char[512];

			GetPrivateProfileString ( Section, Key, DefString, out, 200, Path );

			return out;
		}

		float ReadFloat ( char *Path, char *Section, char *Key, char *DefValue )
		{
			return atof ( ReadString ( Path, Section, Key, DefValue ) );
		}

		int ReadInt ( char *Path, char *Section, char *Key, char *DefValue )
		{
			return atoi ( ReadString ( Path, Section, Key, DefValue ) );
		}

		int ReadStringConvert ( char *Path, char *Section, char *Key, char *DefValue )
		{
			char String[19];

			GetPrivateProfileString ( Section, Key, DefValue, String, 16, Path );

			return StringToKey ( String );
		}

		void WriteString ( char *Path, char *Section, char *Key, char *String )
		{
			WritePrivateProfileString ( Section, Key, String, Path );
		}

		int StringToKey ( char* Key );

		bool FileExists ( const char *FileName )
		{
			return _access ( FileName, 0 ) != -1;
		}
	};

	extern File g_File;
}