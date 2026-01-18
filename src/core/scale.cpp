#include "scale.h"

Scale::Scale(int rootNote, ScaleType type)
    : root(rootNote), scaleType(type) {}

std::vector<int> Scale::getIntervals() const {
    switch (scaleType) {
        case ScaleType::Major:
            return {0, 2, 4, 5, 7, 9, 11};

        case ScaleType::Minor:
            return {0, 2, 3, 5, 7, 8, 10};

        case ScaleType::HarmonicMinor:
            return {0, 2, 3, 5, 7, 8, 11};

        case ScaleType::Dorian:
            return {0, 2, 3, 5, 7, 9, 10};

        case ScaleType::Phrygian:
            return {0, 1, 3, 5, 7, 8, 10};

        case ScaleType::Lydian:
            return {0, 2, 4, 6, 7, 9, 11};

        case ScaleType::Mixolydian:
            return {0, 2, 4, 5, 7, 9, 10};

        case ScaleType::Locrian:
            return {0, 1, 3, 5, 6, 8, 10};

        default:
            return {0, 2, 4, 5, 7, 9, 11};
    }
}

std::vector<int> Scale::getNotes(int octaveCount) const {
    std::vector<int> notes;
    auto intervals = getIntervals();

    for (int octave = 0; octave < octaveCount; ++octave) {
        for (int interval : intervals) {
            notes.push_back(root + interval + (12 * octave));
        }
    }

    return notes;
}

std::string Scale::getName() const {
    switch (scaleType) {
        case ScaleType::Major: return "Major";
        case ScaleType::Minor: return "Minor";
        case ScaleType::HarmonicMinor: return "Harmonic Minor";
        case ScaleType::Dorian: return "Dorian";
        case ScaleType::Phrygian: return "Phrygian";
        case ScaleType::Lydian: return "Lydian";
        case ScaleType::Mixolydian: return "Mixolydian";
        case ScaleType::Locrian: return "Locrian";
        default: return "Unknown";
    }
}
