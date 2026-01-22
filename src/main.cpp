#include <iostream>
#include "core/pattern.h"

using namespace lgen::core;

int main() {
    Pattern pattern;

    pattern.addStep({ StepType::Rest });
    pattern.addStep({ StepType::Note, 0, 1.0f, true }); // root, accent
    pattern.addStep({ StepType::Rest });
    pattern.addStep({ StepType::Note, 2, 0.8f }); // scale degree 

    auto generated = pattern.generate();

    std::cout << "Pattern v2:\n";
    for (const auto& step : generated) {
        if (step.type == StepType::Rest) {
            std::cout << "- ";
        } else {
            std::cout << step.noteOffset;
            if (step.accent) std::cout << "!";
            std::cout << " ";
        }
    }

    std::cout << "\n";
    return 0;
}
