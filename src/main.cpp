#include <iostream>
#include "core/rhythm.h"

int main() {
    Rhythm rhythm(120);
    auto pattern = rhythm.generate(8);

    std::cout << "Rhythm pattern: ";
    for (int step : pattern) {
        std::cout << step << " ";
    }
    std::cout << "\n";

    return 0;
}
