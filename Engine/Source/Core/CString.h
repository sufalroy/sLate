#pragma once

#include "common_defines.h"

namespace slate
{
	SLATE_EXPORT size_t strnlen(const char* str, size_t maxLen);
	SLATE_EXPORT int stricmp(const char* str1, const char* str2);
	SLATE_EXPORT char* strncpy(char* dest, const char* source, size_t count);
	SLATE_EXPORT char* strncpy(char* dest, size_t elements, const char* source, size_t count);
	SLATE_EXPORT char* strncat(char* dest, const char* source, size_t count);
	SLATE_EXPORT char* strncat(char* dest, size_t elements, const char* source, size_t count);
	SLATE_EXPORT int vsnprintf(char* str, size_t maxLen, const char* format, va_list arg);
	SLATE_EXPORT int vsnprintfTrunc(char* str, size_t maxLen, const char* format, va_list arg);
}