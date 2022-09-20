#ifndef INC_2015_UTILS_H
#define INC_2015_UTILS_H

#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string>& split(const std::string& str, const std::string& delim, std::vector<std::string>& out);
std::vector<std::string>& split(const std::string& str, char delim, std::vector<std::string>& out);
std::vector<std::string>& split(const std::string& str, std::vector<std::string>& out);

std::string readFile(const std::string& filename);
std::vector<std::string>& readFileLines(const std::string& filename, std::vector<std::string>& out);

#endif //INC_2015_UTILS_H
