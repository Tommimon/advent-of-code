#include <fstream>
#include <vector>
#include <string>
#include "utils.h"


std::vector<std::string>& split(const std::string& str, const std::string& delim, std::vector<std::string>& out) {
    size_t start = 0;
    size_t end = str.find(delim);
    out.clear();
    while (end != std::string::npos) {
        out.push_back(str.substr(start, end-start));
        start = end+1;
        end = str.find(delim, start);
    }
    if (start < str.size())
        out.push_back(str.substr(start));
    return out;
}


std::vector<std::string>& split(const std::string& str, char delim, std::vector<std::string>& out) {
    return split(str, std::string(1, delim), out);
}


std::vector<std::string>& split(const std::string& str, std::vector<std::string>& out) {
    return split(str, ' ', out);
}

std::string readFile(const std::string &filename) {
    std::ifstream ifs("input");
    std::string input ((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return input;
}

std::vector<std::string> &readFileLines(const std::string &filename, std::vector<std::string> &out) {
    split(readFile(filename), '\n', out);
    return out;
}
