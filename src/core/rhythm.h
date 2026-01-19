#pragma once
#include <vector>

class Rhythm {
public:
    explicit Rhythm(int bpm);

    double secondsPerBeat() const;
    std::vector<double> generate(int steps) const;

private:
    int bpm;
};
