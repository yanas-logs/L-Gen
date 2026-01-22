#include <iostream>
#include "core/pattern.h"
#include "core/rhythm.h"

int main() {
    Rhythm rhythm(120);
    Pattern pattern(8);

    auto r = rhythm.generate(8);

    for (int i = 0; i < r.size(); ++i) {
        if (r[i] == 1) {
            pattern.setStep(i, 60); // C4
        }
    }

    std::cout << "Pattern: ";
    for (const auto& step : pattern.getSteps()) {
        std::cout << step.note << " ";
    }
    std::cout << "\n";

    return 0;
}
