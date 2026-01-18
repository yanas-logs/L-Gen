#pragma once
#include <vector>
#include <string>

enum class ScaleType {
    Major,
    Minor,
    HarmonicMinor,
    Dorian,
    Phrygian,
    Lydian,
    Mixolydian,
    Locrian
};

class Scale {
public:
    Scale(int rootNote, ScaleType type);

    std::vector<int> getNotes(int octaveCount = 1) const;
    std::string getName() const;

private:
    int root;
    ScaleType scaleType;

    std::vector<int> getIntervals() const;
};
