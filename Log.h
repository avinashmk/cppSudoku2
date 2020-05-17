#pragma once
#include "pch.h"

class Log
{
public:
	static void DEBUG(const char* format, ...);
	static void WARN(const char* format, ...);
	static void ERR(const char* format, ...);
	static void INFO(const char* format, ...);
	static void printProgress(const int& progress);
};