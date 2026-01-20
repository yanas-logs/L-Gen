#include "core/rhythm.h"

Rhythm::Rhythm(int bpm) : bpm(bpm) {}

std::vector<int> Rhythm::generate(int steps) const {
    std::vector<int> pattern;
    for (int i = 0; i < steps; ++i) {
        pattern.push_back(i % 2); // basic on/off rhythm
    }
    return pattern;
}
