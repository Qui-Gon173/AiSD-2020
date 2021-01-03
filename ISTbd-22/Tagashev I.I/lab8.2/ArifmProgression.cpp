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
	*_state += _multiplier * 4;
	return *this;
}