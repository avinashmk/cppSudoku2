#include "pch.h"
#include "Log.h"

#include <cstdio>
#include <cstdarg>

void Log::DEBUG(const char* format, ...)
{
	if constexpr(DEBUG_ENABLED)
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

void Log::printProgress(const int& progress)
{
	printf("\r[INFO ] Progress: %d%%...", progress);
	if (progress > 99)
	{
		printf("\n");
	}
}
