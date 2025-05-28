#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <class type>
class clsDblLinkedList
{

private:
	
protected:
	short _Size;

public:

	static class Node
	{
	public:

		type value;
		Node* next;
		Node* prev;
	};

	Node* head;

	clsDblLinkedList()
	{
		head = NULL;
		_Size = 0;
	}

	void InsertAtBeginning(type value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL) 
		{
			head->prev = newNode;
		}

		head = newNode;
		_Size++;
	}

	void PrintList()
	{
		Node* head2 = head;

		while (head2 != NULL)
		{
			cout << head2->value << " ";
			head2 = head2->next;
		}

	}

	Node* Find(type Value)
	{
		Node* head2 = head;
		while (head2 != NULL) 
		{
			if (head2->value == Value)
				return head2;

			head2 = head2->next;
		}

		return NULL;
	}

	void InsertAfter(Node* current, type value) 
	{
		
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;

		if (current->next != NULL) 
		{
			current->next->prev = newNode;//current = 2 next --> 3 prev <-- (2) = 500
		}

		current->next = newNode;
		_Size++;
	}

	void InsertAtEnd(type value) 
	{
		
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;

		if (head == NULL) 
		{
			newNode->prev = NULL;
			head = newNode;
		}

		else 
		{
			Node* current = head;
			while (current->next != NULL) 
			{
				current = current->next;
			}

			current->next = newNode;
			newNode->prev = current;
		}

		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete) 
	{
		
		if (head == NULL || NodeToDelete == NULL) 
		{
			return;
		}

		if (head == NodeToDelete) 
		{
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL) 
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL) 
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		_Size--;
		delete NodeToDelete;
	}

	void DeleteFirstNode() 
	{
		
		if (head == NULL) 
		{
			return;
		}

		Node* temp = head;
		head = head->next;

		if (head != NULL) 
		{
			head->prev = NULL;
		}

		_Size--;
		delete temp;
	}

	void DeleteLastNode() 
	{
		
		if (head == NULL) 
		{
			return;
		}

		if (head->next == NULL) 
		{
			delete head;
			head = NULL;
			return;
		}

		Node* current = head;

		while (current->next->next != NULL) 
		{
			current = current->next;
		}

		Node* temp = current->next;
		current->next = NULL;

		_Size--;
		delete temp;
	}

	short Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Revers()
	{
		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(short Index)
	{
		int Counter = 0;
		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Current = head;

		while (Current != NULL && (Current->next != NULL)) 
		{
			if (Counter == Index)
				break;

			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	type GetItem(short Item)
	{
		Node* ItemNode = GetNode(Item);

		if (ItemNode == NULL)
		{
			return NULL;
		}

		else
		{
			return ItemNode->value;
		}
	}

	bool UpdateItem(int Index, type NewValue)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}

		else
			return false;
	}

	bool InsertAfter(int Index, type value) {

		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}

		else
			return false;
	}

	void SetSize(short size)
	{
		_Size = size;
	}

	short GetSize()
	{
		return _Size;
	}

	__declspec(property(get = GetSize , put = SetSize)) short __Size;
};

