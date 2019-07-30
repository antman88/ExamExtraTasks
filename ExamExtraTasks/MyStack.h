#pragma once

#include "MyList.h"
#include "MyVector.h"
#include <iostream>

using namespace std;

//
class Stack
{
protected:
	Stack* Body;
public:
	virtual void Push(int) = 0;
	virtual int Pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};

// Stack on Vector
class ArrayStack : public Stack
{
private:
	MyVector *arrV;
	int pos;

public:
	ArrayStack(int size)
	{
		this->pos = 0;
		this->arrV = new MyVector(size);
	}
	~ArrayStack()
	{
		delete arrV;
	}

	virtual void Push(int newValue)
	{
		if (!this->isFull())
		{
			(*this->arrV)[this->pos] = newValue;
			this->pos++;
		}
	}
	virtual int Pop()
	{
		if (!this->isEmpty())
		{
			pos--;
			int val = (*this->arrV)[pos];
			return val;
		}
	}
	virtual bool isEmpty()
	{
		return (pos == 0) ? true : false;
	}
	virtual bool isFull()
	{
		return (pos == this->arrV->getSize()) ? true : false;
	}
};

// Stack on List
class ListStack : public Stack
{
private:
	MyList *arrList;
	int pos;

public:
	ListStack() 
	{
		arrList = new MyList(1);
		pos = 0;
	}
	~ListStack() {}

	virtual void Push(int newValue)
	{
		if (!this->isFull())
		{
			arrList->pushFornt(newValue);
			pos++;
		}
	}
	virtual int Pop()
	{
		if (!this->isEmpty())
		{
			pos--;
			int value = arrList->popFront();
			return value;
		}
	}
	virtual bool isEmpty()
	{
		return (pos == 0) ? true : false;
	}
	virtual bool isFull()
	{
		return false;
	}
};


// Stack body
class StackBody : public Stack
{

public:
	StackBody(int size)
	{
		Body = new ArrayStack(size);
	};
	StackBody()
	{
		Body = new ListStack;
	};
	virtual void Push(int items)
	{
		Body->Push(items);
	};
	virtual int Pop()
	{
		return Body->Pop();
	};
	virtual bool isEmpty()
	{
		return Body->isEmpty();
	};
	virtual bool isFull()
	{
		return Body->isFull();
	};
};