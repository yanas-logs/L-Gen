#pragma once
#include <vector>
#include <random>

namespace lgen::core {

enum class StepType {
    Rest,
    Note
};

struct PatternStep {
    StepType type = StepType::Rest;
    int noteOffset = 0;     // relative scale (0 = root)
    float probability = 1.0f; // 0.0 - 1.0
    bool accent = false;
};

class Pattern {
public:
    Pattern();

    void addStep(const PatternStep& step);
    void clear();

    // generate patterns based on probability
    std::vector<PatternStep> generate() const;

    size_t size() const;

private:
    std::vector<PatternStep> steps;
};

} // namespace lgen::core
