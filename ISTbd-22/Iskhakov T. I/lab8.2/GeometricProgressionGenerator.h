#pragma once
#include <algorithm>
#include <iterator>

class GeomGenerator : public std::iterator<std::input_iterator_tag, float>
{
public:
	GeomGenerator(const float first, const float max, int factor);
	~GeomGenerator();

	typedef GeomGenerator const_iterator;

	bool operator!=(GeomGenerator const& other) const;
	bool operator==(GeomGenerator const& other) const;
	typename GeomGenerator::reference operator*() const;
	GeomGenerator& operator++();

	const_iterator begin() const;
	const_iterator end() const;
private:
	float* value;
	int multiplier;
	const float initial;
	const float border;
};

