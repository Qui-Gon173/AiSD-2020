#pragma once
#include <algorithm>
class GeomProgression : public std::iterator<std::input_iterator_tag, int> {
private:
	int* _state;
	int _multiplier;
	const int _seed;
	const int _border;
public:
	typedef GeomProgression const_iterator;
	GeomProgression(const int seed, const int border, int multiplier) : _seed(seed), _border(border), _multiplier(multiplier), _state(new int(seed)) {
	}

	bool operator!=(GeomProgression const& other) const
	{
		return *_state != *other;
	}

	bool operator==(GeomProgression const& other) const
	{
		return *_state == *other._state;
	}

	typename GeomProgression::reference operator*() const
	{
		return *_state;
	}

	GeomProgression& operator++()
	{
		int prev_state = *_state;
		delete _state;
		_state = new int(++++_multiplier);
		return *this;
	}

	const_iterator begin() const {
		return const_iterator(this->_seed, this->_border, this->_multiplier);
	}

	const_iterator end() const {
		return const_iterator(this->_border, this->_border, this->_multiplier);
	}
};