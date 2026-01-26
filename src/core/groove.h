#pragma once

namespace lgen {

class Groove {
public:
    virtual ~Groove() = default;

    // step = index step
    // length = total step
    virtual float timeOffset(int step, int length) const {
        return 0.0f;
    }

    virtual float velocityScale(int step, int length) const {
        return 1.0f;
    }
};

} // namespace lgen
