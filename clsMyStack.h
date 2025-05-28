#pragma once
#include <iostream>
#include "clsMyQueue.h"
using namespace std;
template <class T>
class clsMyStack :public clsMyQueue <T>
{

public:

	void push(T Item)
	{
		clsMyQueue <T>::_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		clsMyQueue<T>::_MyList.DeleteLastNode();
	}

	T Top()
	{
		return clsMyQueue <T>::back();
	}

	T Bottom()
	{
		return clsMyQueue <T>::front();
	}
};