#include "MyList.h"
#include<iostream>
#include<string>

using namespace std;

void MyList::printListFromFirstToLast(MyList* pFirst)
{
	MyList* pCurrent = pFirst;
	while (pCurrent != NULL)
	{
		cout << pCurrent->info << endl;
		pCurrent = pCurrent->pNext;
	}
}

void MyList::printListFromLastToFirst(MyList* pLast)
{
	MyList* pCurrent = pLast;
	while (pCurrent != NULL)
	{
		cout << pCurrent->info << endl;
		pCurrent = pCurrent->pPrev;
	}
}

void MyList::deleteList(MyList* pFirst)
{
	MyList* pCurrent = pFirst;
	while (pCurrent != NULL)
	{
		MyList* tmp = pCurrent;
		pCurrent = pCurrent->pNext;
		delete tmp;
	}
}

void MyList::createList(MyList*& pFirst, int size)
{
	int counter;
	pFirst = new MyList();
	pFirst->info = 1;
	pFirst->pNext = NULL;
	pFirst->pPrev = NULL;
	pLast = pFirst;
	counter = 1;
	MyList* pCurrent = pFirst;
	while (counter < size)
	{
		MyList* pNew = new MyList();
		counter++;
		pNew->info = counter;
		pNew->pNext = NULL;
		pNew->pPrev = NULL;
		pCurrent->pNext = pNew;
		pNew->pPrev = pCurrent;
		pCurrent = pNew;
		pLast = pCurrent;
	}
}

MyList* MyList::createList(int size)
{
	return NULL;
}


std::ostream& operator<< (std::ostream &out, const MyList &obj)
{
	MyList* pCurrent = obj.pFirst;
	while (pCurrent != NULL)
	{
		out << pCurrent->info << endl;
		pCurrent = pCurrent->pNext;
	}

	return out;
}