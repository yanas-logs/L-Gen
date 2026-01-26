#pragma once

namespace lgen {

class Groove {
public:
    virtual ~Groove() = default;

    // micro timing offset (fraction of step)
    virtual float timeOffset(int step, int length) const = 0;

    // velocity / intensity scaling
    virtual float velocityScale(int step, int length) const = 0;
};

} // namespace lgen
