#include <iostream>

#include "core/pattern.h"
#include "core/rhythm.h"
#include "core/sequence.h"

using namespace lgen;

int main() {
    // ======================
    // 1. Pattern (struktur)
    // ======================
    Pattern pattern;

    pattern.addStep({ StepType::Rest });
    pattern.addStep({ StepType::Note, 0, 1.0f, true });
    pattern.addStep({ StepType::Rest });
    pattern.addStep({ StepType::Note, 2, 0.8f });

    // ======================
    // 2. Rhythm (time feel)
    // ======================
    Rhythm rhythm(120); // bpm

    // ======================
    // 3. Sequence (engine)
    // ======================
    Sequence seq(pattern, rhythm);

    std::cout << "Sequence output:\n";

    for (int i = 0; i < pattern.length(); ++i) {
        auto ev = seq.next();

        if (!ev.active) {
            std::cout << "- ";
        } else {
            std::cout << ev.value;
            if (ev.accent) std::cout << "!";
            std::cout << " ";
        }
    }

    std::cout << "\n";
    return 0;
}
