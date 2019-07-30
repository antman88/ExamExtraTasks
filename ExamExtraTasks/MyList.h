#pragma once

#include <iostream>
#include <string>

using namespace std;

class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual int current() = 0;
	virtual int begin() = 0;
	virtual int end() = 0;
	virtual void reset() = 0;
};

class MyList : public Iterator
{
private:
	void deleteList(MyList* pFirst);
	void createList(MyList*& pFirst, int size = 5);
	MyList* createList(int size);
protected:
	int info;
	MyList* pNext;
	MyList* pPrev;
	MyList* pFirst;
	MyList* pLast;
	int size;
	
	int currentIndex;
	MyList* pCurrent;
	
	void printListFromFirstToLast(MyList* pFirst);
	void printListFromLastToFirst(MyList* pLast);
	//
	MyList()
	{
		this->info = 0;
		this->pFirst = NULL;
		this->pLast = NULL;
		this->pNext = NULL;
		this->pPrev = NULL;
	}
	MyList(const MyList& obj) {}
	//
public:
	void print()
	{
		printListFromFirstToLast(this->pFirst);
	}
	void printReverse()
	{
		printListFromLastToFirst(this->pLast);
	}
	MyList(int size)
	{
		this->size = size;
		createList(this->pFirst, size);
		this->pCurrent = this->pFirst;
	}
	~MyList()
	{
		deleteList(pFirst);
	}

	//
	void pushFornt(int value)
	{
		MyList *pNew = new MyList;
		pNew->info = value;
		pNew->pNext = this->pFirst;
		this->pFirst->pPrev = pNew;
		this->pFirst = pNew;
	}

	int popFront()
	{
		MyList* tmp = this->pFirst;
		int value = tmp->info;
		this->pFirst = this->pFirst->pNext;
		delete tmp;
		return value;
	}

	//
	virtual bool hasNext()
	{
		if (this->pCurrent != NULL)
			return true;
		else
			return false;
	}

	virtual int current()
	{
		int currValue = this->pCurrent->info;
		this->pCurrent = this->pCurrent->pNext;
		return currValue;
	}

	virtual int begin()
	{
		return this->pFirst->info;
	}

	virtual int end()
	{
		return this->pLast->info;
	}

	virtual void reset()
	{
		this->pCurrent = this->pFirst;
	}

	//
	friend std::ostream& operator<< (std::ostream &out, const MyList &obj);
};



