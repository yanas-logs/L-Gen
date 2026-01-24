#pragma once
#include <vector>
#include "core/pattern.h"
#include "core/rhythm.h"

namespace lgen {

struct SequenceEvent {
    int step;          // index step (0..n)
    bool active;       // event ? 
    int value;         // pattern value (offset / token)
    bool accent;       // accent / strong hit
};

class Sequence {
public:
    Sequence(const Pattern& pattern,
             const Rhythm& rhythm);

    // get event per step (stateful)
    SequenceEvent next();

    // reset to step 0
    void reset();

    // access metadata
    int length() const;
    int currentStep() const;

private:
    const Pattern& m_pattern;
    const Rhythm&  m_rhythm;

    int m_step = 0;
};

} // namespace lgen
