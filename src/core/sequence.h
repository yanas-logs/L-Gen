#pragma once
#include "core/pattern.h"
#include "core/rhythm.h"
#include "core/groove.h"

namespace lgen {

struct SequenceEvent {
    int   step;
    bool  active;
    int   value;
    bool  accent;

    float timeOffset = 0.0f;
    float velocity   = 1.0f;
};

class Sequence {
public:
    Sequence(const Pattern& pattern,
             const Rhythm& rhythm,
             const Groove* groove = nullptr);

    SequenceEvent next();
    void reset();

    int length() const;
    int currentStep() const;

private:
    const Pattern& m_pattern;
    const Rhythm&  m_rhythm;
    const Groove*  m_groove;

    int m_step = 0;
};

} // namespace lgen
