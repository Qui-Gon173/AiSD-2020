#include "ArifmProgression.h"

bool ArifmProgression::operator!=(ArifmProgression const& other) const
{
	return *_state != *other;
}

bool ArifmProgression::operator==(ArifmProgression const& other) const
{
	return *_state == *other._state;
}

ArifmProgression& ArifmProgression::operator++()
{
	int prev_state = *_state;
	delete _state;
	*_state += _multiplier;
	return *this;
}