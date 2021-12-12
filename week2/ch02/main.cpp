#include  <iostream>
#include <cctype>
#include "stack.h"
int main()
{
	using namespace std;
	Stack st;
	char ch;
	Item item;
	double total=0;
	cout << "Please enter A to PUSH\n" << "P to process a POP ,or Q to quit .\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A' :
		case 'a':
			if (st.isfull())
				cout << "Stack already full！\n";
			else {
				cout << "Enter a item to push:\n";
				cin.getline(item.fullname, 35);
				(cin >> item.payment).get();
				st.push(item);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "Stack is already empty!\n";
			else
			{
				st.pop(item);
				total += item.payment;
				cout << "total:" << total<<endl;
			}
			break;
		}
		cout << "The elements in Stack:\n";
		st.show();
		cout << "\nPlease enter A to PUSH\n" << "P to process a POP ,or Q to quit .\n";
	}
	cout << "Bye \n";
	return 0;
}
