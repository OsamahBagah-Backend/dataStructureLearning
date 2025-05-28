#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDynamicArray
{
protected:
    int _Size = 0;

public:

    T* OriginalArray;
    T* _TempArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;
        _Size = Size;
        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray()
    {
        delete[] OriginalArray;
    }

    bool SetItem(int index, T Value)
    {
        if (index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void reSize(short newSize)
    {
        if (newSize < 0)
        {
            newSize = 0;
        }

        _TempArray = new T[newSize];

        if (newSize < _Size)
        {
            _Size = newSize;
        }

        for (short i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = newSize;
        delete[]OriginalArray;
        OriginalArray = _TempArray;
    }

    void Reverse()
    {
        T Temp ;
        short S = _Size;
        for (short i = 0; i < S; i++)
        {
            Temp = OriginalArray[i];
            OriginalArray[i] = OriginalArray[S - 1];
            OriginalArray[S - 1] = Temp;
            S--;
        }
    }

    void Clear()
    {
        _TempArray = new T[0];
        _Size = 0;
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    T GetItem(short Index)
    {
        return OriginalArray[Index];
    }

    void PrintList()
    {
        for (int i = 0; i < _Size ; i++)
        {
            cout << OriginalArray[i] << " ";
        }
        cout << "\n";
    }

    void DeleteItemByIndex(short Index)
    {
        T* TempArray = new T[_Size - 1];

        if (Index > _Size || Index < 0)
        {
            return;
        }

        else
        {
            short count = 0;
            for (short i = 0; i < _Size; i++)
            {
                if (i != Index)
                {
                    TempArray[count] = OriginalArray[i];
                    count++;
                }
            }

            delete[] OriginalArray;
            _Size--;
            OriginalArray = TempArray;
        }
    }

    void DeleteFirstItem()
    {
        DeleteItemByIndex(0);
    }

    void DeleteLastItem()
    {
        DeleteItemByIndex(_Size - 1);
    }

    int Find(T value)
    {
        for (short i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == value)
            {
                return i;
            }
        }

        return -1;
    }

    void DeleteItemByValue(T value)
    {
        int Index = Find(value);

        if (Index == -1)
        {
            return;
        }

        else
        {
            DeleteItemByIndex(Index);
        }
    }

    bool InsertAt(short Index, T value)
    {
        T* TempArray = new T[_Size +1];

        if (Index > _Size || Index < 0)
        {
            return  false;
        }

        else
        {
            _Size++;
            short count = 0;
            for (short i = 0; i < _Size; i++)
            {
                if (i != Index)
                {
                    TempArray[count] = OriginalArray[i];
                    count++;
                }

                else
                {
                    TempArray[count] = value;
                    count++;
                    TempArray[count] = OriginalArray[i];
                    count++;
                }
            }
            cout << endl;
            delete[]OriginalArray;
            OriginalArray = TempArray;
            return true;
        }
    }

    void InsertAtBeginning(T value)
    {
        InsertAt(0, value);
    }

    bool InsertBefore(T index, T value)
    {
        if (index < 1)
            return InsertAt(0, value);
        else
            return InsertAt(index - 1, value);
    }

    bool InsertAfter(T index, T value)
    {
        if (index >= _Size)
            return InsertAt(_Size - 1, value);
        else
            return InsertAt(index + 1, value);
    }

    bool InsertAtEnd(T value)
    {
        return InsertAt(_Size, value);
    }

    void SetSize(short size)
    {
        _Size = size;
    }

    short GetSize()
    {
        return _Size;
    }

    __declspec(property(get = GetSize, put = SetSize)) short __Size;
};