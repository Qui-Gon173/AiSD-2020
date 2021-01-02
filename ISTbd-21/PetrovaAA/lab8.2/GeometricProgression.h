#pragma once
#include <algorithm>

class GeometricProgression : public std::iterator<std::input_iterator_tag, long>
{
private:
	long* state;
	long multiplier;
	const long seed;
	const long border;

public:
	typedef GeometricProgression const_iterator;
	GeometricProgression(const long Seed, const long  Border, long Multiplier) : seed(Seed), border(Border), multiplier(Multiplier), state(new long(Seed)) {}

	bool operator!=(GeometricProgression const &other) const
	{
		return *state != *other;
	}

	bool operator==(GeometricProgression const &other) const
	{
		return *state == *other;
	}

	typename GeometricProgression::reference operator*() const
	{
		return *state;
	}

	GeometricProgression &operator++()
	{
		long previous_state = *state;
		delete state;
		state = new long(previous_state*multiplier);
		return *this;
	}

	const_iterator begin() const {
		return const_iterator(this->seed, this->border, this->multiplier);
	}

	const_iterator end() const {
		return const_iterator(this->border, this->border, this->multiplier);
	}
};