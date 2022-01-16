//这个一个分治算法，以快速排序为该算法的模型。
#include<iostream>
#include <ctime>
int RandomizeSelect(int* A, int p, int r, int i);
int RandomizedPartition(int* A, int p, int r);
void Swap(int & a, int &b);
int Partition(int* A, int p, int r);
int Partition(int* A, int p, int r)
{
	int x = A[r];//A[r]为主元。
	int i = p - 1,j;
	for (j = p; j < r; j++)
		if (A[j] <= x) {
			i = i + 1;
			Swap(A[i], A[j]);
		}
	Swap(A[i + 1], A[r]);
	return (i + 1);
}
int RandomizedPartition(int* A, int p, int r)
{
	srand(time(0));
	int i = int( rand() / RAND_MAX * (r - p+1) + p);
	Swap(A[r],A[i]);
	return Partition(A, p, r);
}

int RandomizeSelect(int* A, int p, int r, int i)
{
	if (p == r)//数组中只有一个元素。
		return A[p];
	int q ;
	q = RandomizedPartition(A, p, r);//返回主元。
	int k = q-p+1;//计算数组A中小于等于主元的元素个数。
	if (i == k)//说明找到第i小的数了。
		return A[q];
	//数组中小于等于主元的元素的个数大于i时，因为主元左边的数一定小于
	//主元，所以第i小的数在主元的左边。
	else if (i < k)
		return RandomizeSelect(A, p, q - 1, i);
	//当i>k时，说明数组中小于等于主元的元素的个数小于i ,所以第i小的元素一定在
	//主元的右端。所以到主元的右端查找。注意这时候不再是找第i小的了，因为现在
	//是在主元的右边查找，且主元的左边已经有k-1个小于主元的数，所以在右边是应该
	//时搜索主元右端的第i-k个小的元素。
	else return RandomizeSelect(A, q + 1, r, i-k);
}
void Swap(int& a, int& b)
{
	int item;
	item = a;
	a = b;
	b = item;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int A[8] = { 2,8,7,1,3,5,6,4 };
	cout << "请输入i,表示来查找数组中第i小的数;\n";
	int i;
	cin >> i;
	int ans=RandomizeSelect(A, 0, 7, i);
	cout << "第 "<<i<<" 小的数字为： " << ans << endl;
	return 0;
}