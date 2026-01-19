#include <iostream>
#include "core/scale.h"
#include "core/rhythm.h"

int main() {
    Scale scale(60, ScaleType::Minor);
    Rhythm rhythm(120);

    auto notes = scale.getNotes(1);
    auto rhythmPattern = rhythm.generate(8);

    std::cout << "Notes: ";
    for (int n : notes) std::cout << n << " ";

    std::cout << "\nRhythm: ";
    for (double t : rhythmPattern) std::cout << t << " ";

    std::cout << std::endl;
    return 0;
}
