#include "rhythm.h"

Rhythm::Rhythm(int bpm) : bpm(bpm) {}

double Rhythm::secondsPerBeat() const {
    return 60.0 / bpm;
}

std::vector<double> Rhythm::generate(int steps) const {
    std::vector<double> pattern;
    double stepTime = secondsPerBeat() / 2.0; // eighth notes

    for (int i = 0; i < steps; ++i) {
        pattern.push_back(stepTime);
    }

    return pattern;
}
