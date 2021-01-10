#pragma once
#include <iostream>


class Elem
{
	long data; // данные экземпляра
	Elem* Next;
	friend class List;

public:
	Elem(long datat, Elem* Nextt)
	{
		data = datat;
		Next = Nextt;
	};


	long data_return()
	{
		return data;
	}

	Elem* next_return()
	{
		return Next;
	}

	long operator*() const
	{
		return data;
	};
};

