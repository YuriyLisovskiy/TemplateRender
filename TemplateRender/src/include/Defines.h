#pragma once

#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#define ROOT_DIR std::string(_getcwd(0, 0)) + "/"
#define LOCAL_TIME(now, t) localtime_s(&now, &t);
#elif defined(__unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)
std::string getRootDir();
#define ROOT_DIR getRootDir()
#define LOCAL_TIME(now, t) localtime_r(&(t), &(now));
#endif
