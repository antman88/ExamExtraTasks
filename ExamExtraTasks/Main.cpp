#include "MyStack.h"
#include "MyList.h"
#include "MyVector.h"
#include <iostream>

using namespace std;

//
int main()
{
	//
	Stack *stack = new StackBody();

	stack->Push(1);
	stack->Push(2);
	stack->Push(3);

	while (!stack->isEmpty())
	{
		cout << stack->Pop() << endl;
	}

	//
	system("pause");
	return 0;
}