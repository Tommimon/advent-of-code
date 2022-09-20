#include <iostream>
#include <fstream>

int main() {
    std::ifstream ifs("input");
    std::string input((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

}
