#include <iostream>
#define eps 1e-8
using namespace std;
bool count24(double* arr,const  int n);
bool  count24(double* arr, const int n)
{
	//���ڵ����ʣ�ѡȡ������֮����ô�洢������������֮��������������ϲ��󣬹�ģ��1�ˣ���μ������㡣
	//������ʾ�𰸣�������һ���뷨����ʹ��һ��char���͵����顣
	//�ҵ��뷨��ֻ��Ҫ�����ĸ�����Ȼ��Ϳ����������Ҫ�����׺���ʽ��
	if (n == 1)
	{
		if (fabs(arr[0] - 24)<eps)//�ݹ�߽�
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
		cout << "�������ĸ�����" << endl;
		int i=0;
		for (i = 0; i < 4; i++)
			cin >> arr[i];
		if (count24(arr, 4)) cout << true;
		else cout<< false;
		cout << "\n";
	} while (fabs(arr[0]) > eps);
	return 0;
}