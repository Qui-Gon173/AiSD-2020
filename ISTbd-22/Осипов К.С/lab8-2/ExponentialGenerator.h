#pragma once
#include "DoubleList.h"

class ExponentialGenerator : public iterator<input_iterator_tag, int>
{
public:
	friend class DoubleList<int>;

	ExponentialGenerator(int base, unsigned long long max)
	{
		this->max = max;
		this->base = base;
		this->state = new int(base);
	}

	~ExponentialGenerator()
	{
		delete state;
	}

	bool operator!=(ExponentialGenerator const& other) const;
	bool operator==(ExponentialGenerator const& other) const;

	bool operator<=(ExponentialGenerator const& other) const;
	bool operator>=(ExponentialGenerator const& other) const;

	typename ExponentialGenerator::reference operator*() const;
	ExponentialGenerator& operator++();

	ExponentialGenerator begin() const;
	ExponentialGenerator end() const;

private:
	int* state;
	int base;
	unsigned long long max;
};

inline bool ExponentialGenerator::operator!=(ExponentialGenerator const& other) const
{
	return *this->state != *other.state;
}

inline bool ExponentialGenerator::operator==(ExponentialGenerator const& other) const
{
	return *this->state == *other.state;
}

inline bool ExponentialGenerator::operator<=(ExponentialGenerator const& other) const
{
	return *this->state <= *other.state;
}

inline bool ExponentialGenerator::operator>=(ExponentialGenerator const& other) const
{
	return *this->state >= *other.state;
}

inline typename ExponentialGenerator::reference ExponentialGenerator::operator*() const
{
	return *state;
}

inline ExponentialGenerator& ExponentialGenerator::operator++()
{
	int old_state = *state;
	delete state;
	state = new int(base * old_state);
	return *this;
}

inline ExponentialGenerator ExponentialGenerator::begin() const
{
	return ExponentialGenerator(this->base, this->max);
}

inline ExponentialGenerator ExponentialGenerator::end() const
{
	return ExponentialGenerator(this->max, this->max);
}
