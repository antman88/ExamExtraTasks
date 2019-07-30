#include "MyVector.h"
#include <iostream>

//
MyVector::MyVector(int size)
{
	this->size = size;
	this->pArr = new int[size];
	for (int i = 0; i < size; i++)
		this->pArr[i] = i + 1;
}

MyVector::~MyVector()
{
	delete[] this->pArr;
}

void MyVector::printFromFirstToLast()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->pArr[i] << endl;
	}
}

int& MyVector::operator[](int i)
{
	return this->pArr[i];
};

const int& MyVector::operator[](int i)const
{
	return this->pArr[i];
};

ostream& operator<<   (ostream& os, const MyVector& t)
{
	for (int i = 0; i < t.size; i++)
	{
		os << t.pArr[i] << endl;
	}

	return os;
}
