#include "pattern.h"

namespace lgen::core {

Pattern::Pattern() = default;

void Pattern::addStep(const PatternStep& step) {
    steps.push_back(step);
}

void Pattern::clear() {
    steps.clear();
}

size_t Pattern::size() const {
    return steps.size();
}

std::vector<PatternStep> Pattern::generate() const {
    std::vector<PatternStep> result;
    result.reserve(steps.size());

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (const auto& step : steps) {
        float roll = dist(gen);

        if (roll <= step.probability) {
            result.push_back(step);
        } else {
            // fail -> rest
            result.push_back(PatternStep{ StepType::Rest });
        }
    }

    return result;
}

} // namespace lgen::core
