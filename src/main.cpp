#include <iostream>
#include "core/pattern.h"
#include "core/rhythm.h"
#include "core/sequence.h"
#include "core/groove/swing.h"

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
    // 3. Groove (human feel)
    // ======================
    SwingGroove swing(0.6f);

    // ======================
    // 4. Sequence (engine)
    // ======================
    Sequence seq(pattern, rhythm, &swing);

    std::cout << "Sequence output:\n";

    for (int i = 0; i < pattern.length(); ++i) {
        auto ev = seq.next();

        if (!ev.active) {
            std::cout << "- ";
        } else {
            std::cout << ev.value;
            if (ev.accent) std::cout << "!";
            std::cout << "(t:" << ev.timeOffset
                      << ",v:" << ev.velocity << ") ";
        }
    }

    std::cout << "\n";
    return 0;
}
