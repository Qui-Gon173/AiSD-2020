#pragma once

#include <iterator>

using namespace std;

class Exponential_Iterator : public iterator<input_iterator_tag, float>
{
	private:
		float A; //a
		float N; //n
		float step; //step
		float it_count = 0;
		float *value;
	public:
		Exponential_Iterator(float A, float N, float step, float it_count) : A(A), N(N), step(step), it_count(it_count)
		{
			value = new float(A);
		};
		~Exponential_Iterator()
		{
			delete value;
		}
		bool operator!=(Exponential_Iterator& another) const
		{
			return it_count != another.it_count;
		}
		bool operator==(Exponential_Iterator& another) const
		{
			return it_count == another.it_count;
		}
		typename Exponential_Iterator::reference operator*() const {
			*value = 1;
			for (int i = 0; i < N; i++) {
				*value *= A;
			}
			return *value;
			 

		}
		Exponential_Iterator& operator++()
		{
			
				N = N + step;
				it_count++;
				return *this;
			
		}
};

class Exponential_Generator : public iterator<input_iterator_tag, int>
{
	private:
		float A; //a 
		float N; //n
		float step; //step
		float at_step;
	public:
		using iterator = Exponential_Iterator;
		using const_iterator = Exponential_Iterator const;
		Exponential_Generator(float A, float N, float step, float at_step) : A(A), N(N), step(step), at_step(at_step) {};
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
			return iterator(A, N, step, at_step);
		}
		iterator cbegin() const
		{
			return const_iterator(A, N,step, 0);
		}
		iterator cend() const
		{
			return const_iterator(A, N, step,at_step);
		}
};
