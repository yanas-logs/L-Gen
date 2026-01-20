#pragma once
#include <vector>

class Rhythm {
public:
    explicit Rhythm(int bpm);

    std::vector<int> generate(int steps) const;

private:
    int bpm;
};
