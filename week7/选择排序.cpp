#include <iostream>
#include<string>
#define N 20
void insertionsort(int* A, int n);
int select(int* A, int p, int r,int ii);
int partition(int* A, int p, int r, int x);
void Swap(int& a, int& b);
void insertionsort(int* A, int n)
{
	if (n<=1)
		return;
	insertionsort(A, n - 1);
	int i = n-1;
	int temp = A[i];
	while (i > 0 && temp < A[i - 1])
	{
		A[i] = A[i - 1];
		i--;
	}
	A[i] = temp;	
}
int select(int* A, int p, int r, int ii)
{
	int n = r - p + 1;
	int k = n / 5;//分组时，每组中有5个元素的组数。
	int l = n % 5;//分组时，组中不足5个元素时，改组中的元素数。
	int j = 0;
	if (n == 1) 
		return A[p];//递归边界
	//int arr[N]{ 0 };
	int* arr = new int[k + 1]{};//创建临时数组来存储子数组中的中位数。因为n个数能分成k+1组，每组取一个中位数，则有k+1个。
	for (j = 0; j < k; j++) {//对有五个元素的组进行插入排序。
		insertionsort(&A[p + j * 5], 5);
		for (int iii = 0; iii < 5; iii++)
			std::cout << A[p + j * 5 + iii] << "  ";
		std::cout << "\n";
	}
	insertionsort(&A[p + k * 5], l);//对元素数不足5但不小于0的组进行插入排序。
	for (int iii = 0; iii < l; iii++)
		std::cout <<A[p + k * 5 + iii] << "  ";
	std::cout << "\n";
	int i, q = 0;
	//std::cout << "每组中的中位数：\n";
	if (k != 0) {
		for (i = p + 2; i < p + k * 5; i = i + 5) {
			//将有5个元素且排序好的组中的中位数拿出来，放在临时数组arr中.
			arr[q] = A[i];
			std::cout << arr[q] << " ";
			q++;
		}
	}
	if (l != 0) {
		int jj = p + k * 5 + (l - 1) / 2;
			arr[q] = A[jj];
			//将元素数不足5个的且取排好序后组中的中位数拿出来，放入arr
			std::cout << arr[q] << " ";
			q++;
	}
	std::cout << "\n";
	//这里的-1时最精妙的部分！
	int x = select(arr, 0, q - 1, -1);//x表示的含义是当前数组A的各子数组中的中位数的中位数。
	delete[]arr;
	//使用完arr后，就释放掉内存，关于这种在递归函数的内存释放问题，
	//因为每一次递归都是一样的，所以假设现在是某一次递归中，上面两行语句的意思是，
	//我现在利用动态开辟的数组来求解x，当我得到x后，然后释放arr动态分配的内存，
	// （不要看到第一条语句中有递归调用，就去套娃，把自己套进去，而是！！！！只在某一次时！！！！！！）。
	if (ii >= 0) {
		int kk = partition(A, p, r, x);//这一步借用快速排序的主程序，找到kk,即数组A中下标为0到kk的元素都小于x.
		if (kk == ii) return A[kk];
		else if (kk > ii)
			return select(A, p, kk - 1, ii);
		else if (kk < ii)
			return select(A, kk + 1, r, ii);
		//这里和《算法导论》中不一样是因为，我们始终没有将A数组变小，只是改变数组元素的顺序，
		//而且，在缩窄范围寻找时，我们使用的时下标来达到收缩的目的，所以用ii来表示想要的数。
	}
	return x;
}
int partition(int* A, int p, int r, int x)
{
	int xx = x;
	int i = p - 1, j;
	for (j = p; j <=r; j++) {
		if (A[j] <= xx) {
			i++;
			Swap(A[i], A[j]);
		}
	}
	return (i);
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
	int n;
	int A[19] = { 2,1,5,4,3,6,9,8,7,0,11,12,21,15,13,88,55,24,100 };
	std::cout << "请输入n,表示查找数组中第i小的数！\n"<<"输入的 n 的取值范围为n>0!!!!!!!!!!!!!!\n";
	std::cin >> n;
	if (n > 0){
		std::cout << "求解过程！\n";
		int  p = select(A, 0, 18, n - 1);
		std::cout << "求解过程结束！\n";
		std::cout << "p:" << p << "\n";
	}
	else 
		std::cout << "你的输入有误！请退出重试！\n";
	return 0;
}