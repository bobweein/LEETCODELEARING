#include "stack.h"
#include <iostream>
Stack::Stack()
{
	top = 0;
}
bool Stack::isempty()const
{
	return top == 0;
}
bool Stack::isfull()const
{
	return top == Max;
}
bool Stack::push(const Item &item)
{
	if (!this->isfull())
	{
		items[top++] = item;
		return true;
	}
	else return false;
}
bool Stack::pop(Item& item)
{
	if (!this->isempty())
	{
		item = items[--top];
		return true;
	}
	else return false;
}
void Stack::show()
{
	if (top == 0) std::cout << "Stack is already empty!\n";
	else 
	{
		for (int i = 0; i < top; i++)
			std::cout << this->items[i].fullname << "\t" << this->items[i].payment << std::endl;
	}
}
