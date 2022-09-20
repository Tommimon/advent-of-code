#include <iostream>
#include <vector>
#include "utils.h"

void strToSides(const std::string& description, std::vector<int>& out) {
    std::vector<std::string> strings;
    split(description, 'x', strings);
    out.clear();
    std::transform(strings.begin(), strings.end(), std::back_inserter(out),
                   [&](std::string& s) {
                       return stoi(s);
                   });
}

int sidesToPaper(const std::vector<int>& sides) {
    int max = *std::max_element(sides.begin(), sides.end());
    return 2 * sides[0] * sides[1] + 2 * sides[1] * sides[2] + 2 * sides[0] * sides[2] + sides[0] * sides[1] * sides[2] / max;
}

int sidesToRibbon(const std::vector<int>& sides) {
    int max = *std::max_element(sides.begin(), sides.end());
    return sides[0] * sides[1] * sides[2] + 2 * sides[0] + 2 * sides[1] + 2 * sides[2] - 2 * max;
}

int main() {
    std::vector<std::string> lines;
    readFileLines("input", lines);

    std::vector<int> sides;
    int paper = 0;
    int ribbon = 0;
    for (const auto& l: lines) {
        strToSides(l, sides);
        paper += sidesToPaper(sides);
        ribbon += sidesToRibbon(sides);
    }
    std::cout << paper << std::endl;
    std::cout << ribbon << std::endl;
}
