#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory>
template<typename ... Args>
std::string string_format(const std::string& format, Args ... args){
    size_t size = 1 + snprintf(nullptr, 0, format.c_str(), args ...);  // Extra space for \0
    // unique_ptr<char[]> buf(new char[size]);
    char bytes[size];
    std::snprintf(bytes, size, format.c_str(), args ...);
    return std::string(bytes);
}
bool bmpToVideo(const char* format, int from, int height, int width, int fps, const char* outputLoc){
	std::string cmd = string_format("ffmpeg -r %d -start_number %d -i %s -s %dX%d -vf fps=%d %s", fps, from, format, width, height, fps, outputLoc);
	printf("Run command: %s\n", cmd.c_str());
	return system(cmd.c_str());
}