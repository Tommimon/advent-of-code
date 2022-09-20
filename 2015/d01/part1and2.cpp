#include <iostream>
#include <fstream>


int main() {
    std::ifstream ifs("input");
    std::string input((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    //std::cout << input << std::endl;
    int floor = 0;
    int firstBasement = 0;
    for (int i = 0; i < input.size(); ++i) {
        floor += -1 + 2 * (input[i] == '(');
        if (floor == -1 && firstBasement == 0)
            firstBasement = i+1;
    }
    std::cout << floor << std::endl;
    std::cout << firstBasement << std::endl;
}
