/***********************************************************************
Author: Zihan Chen (vczh)
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "Console.h"

namespace vl
{
	namespace console
	{
		
/***********************************************************************
Console
***********************************************************************/

		void Console::Write(const wchar_t* string)
		{
			Write(string, wcslen(string));
		}

		void Console::Write(const WString& string)
		{
			Write(string.Buffer(), string.Length());
		}

		void Console::WriteLine(const WString& string)
		{
			Write(string);
			Write(L"\r\n");
		}
	}
}
