#pragma once
#include "../groove.h"
#include <algorithm>

namespace lgen {

class SwingGroove : public Groove {
public:
    explicit SwingGroove(float amount = 0.5f)
        : m_amount(std::clamp(amount, 0.0f, 1.0f)) {}

    float timeOffset(int step, int /*length*/) const override {
        // swing on off-beat
        return (step % 2 == 1) ? m_amount * 0.5f : 0.0f;
    }

    float velocityScale(int step, int /*length*/) const override {
        return (step % 2 == 0) ? 1.1f : 0.9f;
    }

private:
    float m_amount;
};

} // namespace lgen
