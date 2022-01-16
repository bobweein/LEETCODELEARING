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
	int k = n / 5;//����ʱ��ÿ������5��Ԫ�ص�������
	int l = n % 5;//����ʱ�����в���5��Ԫ��ʱ�������е�Ԫ������
	int j = 0;
	if (n == 1) 
		return A[p];//�ݹ�߽�
	//int arr[N]{ 0 };
	int* arr = new int[k + 1]{};//������ʱ�������洢�������е���λ������Ϊn�����ֳܷ�k+1�飬ÿ��ȡһ����λ��������k+1����
	for (j = 0; j < k; j++) {//�������Ԫ�ص�����в�������
		insertionsort(&A[p + j * 5], 5);
		for (int iii = 0; iii < 5; iii++)
			std::cout << A[p + j * 5 + iii] << "  ";
		std::cout << "\n";
	}
	insertionsort(&A[p + k * 5], l);//��Ԫ��������5����С��0������в�������
	for (int iii = 0; iii < l; iii++)
		std::cout <<A[p + k * 5 + iii] << "  ";
	std::cout << "\n";
	int i, q = 0;
	//std::cout << "ÿ���е���λ����\n";
	if (k != 0) {
		for (i = p + 2; i < p + k * 5; i = i + 5) {
			//����5��Ԫ��������õ����е���λ���ó�����������ʱ����arr��.
			arr[q] = A[i];
			std::cout << arr[q] << " ";
			q++;
		}
	}
	if (l != 0) {
		int jj = p + k * 5 + (l - 1) / 2;
			arr[q] = A[jj];
			//��Ԫ��������5������ȡ�ź�������е���λ���ó���������arr
			std::cout << arr[q] << " ";
			q++;
	}
	std::cout << "\n";
	//�����-1ʱ���Ĳ��֣�
	int x = select(arr, 0, q - 1, -1);//x��ʾ�ĺ����ǵ�ǰ����A�ĸ��������е���λ������λ����
	delete[]arr;
	//ʹ����arr�󣬾��ͷŵ��ڴ棬���������ڵݹ麯�����ڴ��ͷ����⣬
	//��Ϊÿһ�εݹ鶼��һ���ģ����Լ���������ĳһ�εݹ��У���������������˼�ǣ�
	//���������ö�̬���ٵ����������x�����ҵõ�x��Ȼ���ͷ�arr��̬������ڴ棬
	// ����Ҫ������һ��������еݹ���ã���ȥ���ޣ����Լ��׽�ȥ�����ǣ�������ֻ��ĳһ��ʱ����������������
	if (ii >= 0) {
		int kk = partition(A, p, r, x);//��һ�����ÿ���������������ҵ�kk,������A���±�Ϊ0��kk��Ԫ�ض�С��x.
		if (kk == ii) return A[kk];
		else if (kk > ii)
			return select(A, p, kk - 1, ii);
		else if (kk < ii)
			return select(A, kk + 1, r, ii);
		//����͡��㷨���ۡ��в�һ������Ϊ������ʼ��û�н�A�����С��ֻ�Ǹı�����Ԫ�ص�˳��
		//���ң�����խ��ΧѰ��ʱ������ʹ�õ�ʱ�±����ﵽ������Ŀ�ģ�������ii����ʾ��Ҫ������
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
	std::cout << "������n,��ʾ���������е�iС������\n"<<"����� n ��ȡֵ��ΧΪn>0!!!!!!!!!!!!!!\n";
	std::cin >> n;
	if (n > 0){
		std::cout << "�����̣�\n";
		int  p = select(A, 0, 18, n - 1);
		std::cout << "�����̽�����\n";
		std::cout << "p:" << p << "\n";
	}
	else 
		std::cout << "��������������˳����ԣ�\n";
	return 0;
}