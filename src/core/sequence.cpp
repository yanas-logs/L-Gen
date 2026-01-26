#include "core/sequence.h"

namespace lgen {

Sequence::Sequence(const Pattern& pattern,
                   const Rhythm& rhythm,
                   const Groove* groove)
    : m_pattern(pattern)
    , m_rhythm(rhythm)
    , m_groove(groove) {}

SequenceEvent Sequence::next() {
    SequenceEvent ev;
    ev.step = m_step;

    int p = m_pattern.at(m_step);
    ev.active = (p >= 0);
    ev.value  = p;
    ev.accent = m_rhythm.isAccent(m_step);

    if (m_groove) {
        ev.timeOffset = m_groove->timeOffset(m_step, length());
        ev.velocity   = m_groove->velocityScale(m_step, length());
    }

    m_step = (m_step + 1) % length();
    return ev;
}

void Sequence::reset() {
    m_step = 0;
}

int Sequence::length() const {
    return m_pattern.length();
}

int Sequence::currentStep() const {
    return m_step;
}

} // namespace lgen
