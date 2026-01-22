#include "core/pattern.h"

Pattern::Pattern(int steps)
    : steps(steps, {-1, 0}) {}

void Pattern::setStep(int index, int note, int velocity) {
    if (index < 0 || index >= steps.size()) return;
    steps[index] = {note, velocity};
}

const std::vector<Step>& Pattern::getSteps() const {
    return steps;
}

int Pattern::size() const {
    return steps.size();
}
