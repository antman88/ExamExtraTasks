#pragma once

#include <iostream>

using namespace std;

//
class IteratorMyList
{
public:
	virtual bool hasNext() = 0;
	virtual int current() = 0;
	virtual int begin() = 0;
	virtual int end() = 0;
	virtual void reset() = 0;
};

//
class MyVector : public IteratorMyList
{
private:
	int size;
	int *pArr;

	int currIndex;

	void printFromFirstToLast();

public:
	
	MyVector(int size);
	~MyVector();

	void print()
	{
		printFromFirstToLast();
	}

	int getSize()
	{
		return this->size;
	}

	virtual bool hasNext()
	{
		if (this->currIndex < this->size - 1)
			return true;
		else
			return false;
	}

	virtual int current()
	{
		int currValue = this->pArr[this->currIndex];
		this->currIndex++;
		return currValue;
	}

	virtual int begin()
	{
		return this->pArr[0];
	}

	virtual int end()
	{
		return this->pArr[this->size - 1];
	}

	virtual void reset()
	{
		this->currIndex = 0;
	}

	friend ostream&	operator << (ostream& os, const MyVector& t);
	int& operator[](int);
	const int& operator[](int i) const;
};