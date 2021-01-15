#pragma once

#include <iterator>

using namespace std;

class ProgressionIterator : public iterator<input_iterator_tag, float>
{
	private:
		float A;
		float N;
		float step; 
		float iterationsCount = 0;
		float* value;
	public:
		ProgressionIterator(float A, float N, float step, float iterationsCount) : A(A), N(N), step(step), iterationsCount(iterationsCount)
		{
			value = new float(A);
		};
		~ProgressionIterator()
		{
			delete value;
		}
		bool operator!=(ProgressionIterator& another) const
		{
			return iterationsCount != another.iterationsCount;
		}
		bool operator==(ProgressionIterator& another) const
		{
			return iterationsCount == another.iterationsCount;
		}
		typename ProgressionIterator::reference operator*() const 
		{
			*value = 1;
			for (int i = 0; i < N; i++) 
			{
				*value *= A;
			}
			return *value;
		}
		ProgressionIterator& operator++()
		{
			N = N + step;
			iterationsCount++;
			return *this;
		}
};

class ProgressionGenerator : public iterator<input_iterator_tag, int>
{
	private:
		float A;
		float N;
		float step; 
		float maxStepCount;
	public:
		using iterator = ProgressionIterator;
		using const_iterator = ProgressionIterator const;
		ProgressionGenerator(float A, float N, float step, float maxStepCount) : A(A), N(N), step(step), maxStepCount(maxStepCount) {};
		int lenght()
		{
			return this->step;
		}
		iterator begin()
		{
			return iterator(A, N, step, 0);
		}
		iterator end()
		{
			return iterator(A, N, step, maxStepCount);
		}
		iterator cbegin() const
		{
			return const_iterator(A, N, step, 0);
		}
		iterator cend() const
		{
			return const_iterator(A, N, step, maxStepCount);
		}
};