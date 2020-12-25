#pragma once
#include <algorithm>
class ArifmProgression : public std::iterator<std::input_iterator_tag, int> {
private:
	int* _state;
	int _multiplier;
	const int _seed;
	const int _border;
public:
	typedef ArifmProgression const_iterator;
	ArifmProgression(const int seed, const int border, int multiplier) : _seed(seed), _border(border), _multiplier(multiplier), _state(new int(seed)) {
	}

	bool operator!=(ArifmProgression const& other) const;

	bool operator==(ArifmProgression const& other) const;

	typename ArifmProgression::reference operator*() const
	{
		return *_state;
	}

	ArifmProgression& operator++();

	const_iterator begin() const {
		return const_iterator(this->_seed, this->_border, this->_multiplier);
	}

	const_iterator end() const {
		return const_iterator(this->_border, this->_border, this->_multiplier);
	}
};