#pragma once
#include <vector>

struct Step {
    int note;      // MIDI note number, -1 = rest
    int velocity;  // 0–127
};

class Pattern {
public:
    explicit Pattern(int steps);

    void setStep(int index, int note, int velocity = 100);
    const std::vector<Step>& getSteps() const;
    int size() const;

private:
    std::vector<Step> steps;
};
