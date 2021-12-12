#ifndef _STACK_H
#define _STACK_H
typedef struct customer
{
	char fullname[35];
	double payment;
}Item;
class Stack
{
private :
	static const int Max = 10;
	Item items[Max];
	int top;
public:
	Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item& item);
	bool pop(Item& item);
	void show();
};
#endif 
