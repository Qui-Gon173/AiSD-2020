#pragma once

#include <iterator>

using namespace std;

class GeometricProgressionIterator : public iterator<input_iterator_tag, int>
{
	private:
		int initial;
		int multiplier;
		int iterations;
		int* value;
	public:
		GeometricProgressionIterator(int initial, int multiplier, int iterations) : initial(initial), multiplier(multiplier), iterations(iterations)
		{
			value = new int(initial);
		};
		~GeometricProgressionIterator()
		{
			delete value;
		}
		bool operator!=(GeometricProgressionIterator& another) const
		{
			return this->iterations != another.iterations;
		}
		typename GeometricProgressionIterator::reference operator*() const {
			return *this->value;
		}
		GeometricProgressionIterator& operator++()
		{
			*value *= multiplier;
			iterations++;
			return *this;
		}
};

class GeometricProgressionGenerator : public iterator<input_iterator_tag, int>
{
	private:
		int initial;
		int multiplier;
		int maxStepCount;
	public:
		using iterator = GeometricProgressionIterator;
		using const_iterator = GeometricProgressionIterator const;
		GeometricProgressionGenerator(int initial, int multiplier, int maxStepCount) : initial(initial), multiplier(multiplier), maxStepCount(maxStepCount) {};
		int lenght()
		{
			return this->maxStepCount;
		}
		iterator begin()
		{
			return iterator(initial, multiplier, 0);
		}
		iterator end()
		{
			return iterator(initial, multiplier, maxStepCount);
		}
		iterator cbegin() const
		{
			return const_iterator(initial, multiplier, 0);
		}
		iterator cend() const
		{
			return const_iterator(initial, multiplier, maxStepCount);
		}
};