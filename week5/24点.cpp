#include <iostream>
#define eps 1e-8
using namespace std;
bool count24(double* arr,const  int n);
bool  count24(double* arr, const int n)
{
	//现在的疑问，选取两个数之后，怎么存储这两个数计算之后的数，两个数合并后，规模减1了，如何继续运算。
	//关于显示答案，现在有一个想法就是使用一个char类型的数组。
	//我的想法是只需要输入四个数，然后就可以输出满足要求的中缀表达式。
	if (n == 1)
	{
		if (fabs(arr[0] - 24)<eps)//递归边界
			return true;
		else return false;
	}
	int i = 0, j = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			double *temp=new double [n-1]{};
			int iTem = 0;
			for (int k = 0; k < n; k++)
				if (k != i && k != j) temp[iTem++] = arr[k];
			
			temp[iTem] = arr[i] + arr[j];
			if (count24(temp, n - 1)) { delete[]temp; return true; }
			temp[iTem] = arr[i] * arr[j];
			if (count24(temp, n - 1)) {
				delete[]temp; return true;
			}
			temp[iTem] = arr[i] - arr[j];
			if (count24(temp, n - 1)) {
				delete[]temp; return true;
			}
			temp[iTem] = arr[j] - arr[i];
			if (count24(temp, n - 1)) {
				delete[]temp; return true;
			}
			if (fabs(arr[j]) > eps)
			{
				temp[iTem] = arr[i] / arr[j];
				if (count24(temp, n - 1)) {
					delete[]temp; return true;
				}
			}
			if (fabs(arr[i]) > eps)
			{
				temp[iTem] = arr[j] / arr[i];
				if (count24(temp, n - 1)) {
					delete[]temp; return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	double arr[5]{};
	do {
		cout << "请输入四个数：" << endl;
		int i=0;
		for (i = 0; i < 4; i++)
			cin >> arr[i];
		if (count24(arr, 4)) cout << true;
		else cout<< false;
		cout << "\n";
	} while (fabs(arr[0]) > eps);
	return 0;
}