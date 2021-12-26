#include <iostream>
using std::cout;
int Binary(int * A, int p, int r, int v);
int Binary_Search(int* A, int p, int r, int v);
//使用递归先确定一个过程
int Binary(int * A, int p, int r, int v)
{
	int j = p;
	/*for (j = p; j <= r; j++)
		cout << A[j] << " ";
	cout << "\n";*/
	for (j = p; j <= r; j++)
		if (A[j] == v)
			return j;
	return 0;
}
int Binary_Search(int * A, int p, int r, int v)
{
	int q=0;
	if ( p==0&&r==0 && A[0] == v)
		return 0;
	if (p < r)
	{
		q = (p + r) / 2;
		if (A[q] > v)
		{
			Binary_Search(A, p, q, v);
			return Binary(A, p, q, v);
		}
		else
		{
			Binary_Search(A, q + 1, r, v);
			return Binary(A, q + 1, r, v);
		}
	}
	return 0;
}
int main()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a=Binary_Search(A, 0, 9, 8);
	cout << "元素V在数组的第 " << a<<" 位上！\n";
	return 0;
}