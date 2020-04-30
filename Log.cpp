#include "pch.h"
#include "Log.h"

#include <cstdio>
#include <cstdarg>

constexpr bool DEBUG_ENABLED = false;

void Log::DEBUG(const char* format, ...)
{
	if (DEBUG_ENABLED)
	{
		va_list arg;
		va_start(arg, format);
		printf("[DEBUG] ");
		vprintf(format, arg);
		va_end(arg);
		printf("\n");
	}
}

void Log::WARN(const char* format, ...)
{
	va_list arg;
	va_start(arg, format);
	printf("[WARN ] ");
	vprintf(format, arg);
	va_end(arg);
	printf("\n");
}

void Log::ERR(const char* format, ...)
{
	va_list arg;
	va_start(arg, format);
	printf("[ERR  ] ");
	vprintf(format, arg);
	va_end(arg);
	printf("\n");
}

void Log::INFO(const char * format, ...)
{
	va_list arg;
	va_start(arg, format);
	printf("[INFO ] ");
	vprintf(format, arg);
	va_end(arg);
	printf("\n");
}
