#pragma once
#include <algorithm>
class ArifmProgression : public std::iterator<std::input_iterator_tag, int> {
private:
	int* _state;
	int _mnojitel;
	const int _seed;
	const int _granica;
public:
	typedef ArifmProgression const_iterator;
	ArifmProgression(const int seed, const int border, int multiplier) : _seed(seed), _granica(border), _mnojitel(multiplier), _state(new int(seed)) {
	}

	bool operator!=(ArifmProgression const &other) const
	{
		return *_state != *other;
	}

	bool operator==(ArifmProgression const &other) const
	{
		return *_state == *other._state;
	}

	typename ArifmProgression::reference operator*() const
	{
		return *_state;
	}

	ArifmProgression &operator++()
	{
		int prev_state = *_state;
		delete _state;
		_state = new int(prev_state + _mnojitel);
		return *this;
	}

	const_iterator begin() const {
		return const_iterator(this->_seed, this->_granica, this->_mnojitel);
	}

	const_iterator end() const {
		return const_iterator(this->_granica, this->_granica, this->_mnojitel);
	}
};