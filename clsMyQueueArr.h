#pragma once
#include <iostream>
#include"clsDynamicArray.h"
using namespace std;
template <class T>
class clsMyQueueArr
{
protected:
	 clsDynamicArray <T> _MyList;
public:

	void push(T Item)
	{
		if (_MyList.__Size == 0)
		{
			_MyList.InsertAtBeginning(Item);
			//_MyList.__Size++;
		}

		else
		{
			_MyList.InsertAtEnd(Item);
			//_MyList.__Size++;
		}
	}

	void pop()
	{
		_MyList.DeleteFirstItem();
		//_MyList.__Size--;
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.__Size;
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(_MyList.__Size - 1);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		short Size = _MyList.__Size;
		if (Index < 0 || Index >= Size)
		{
			return;
		}

		else
		{
			_MyList.OriginalArray[Index] = NewValue;
		}
	}

	void InsertAfter(int Index, T NewValue)
	{
		_MyList.InsertAfter(Index, NewValue);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};