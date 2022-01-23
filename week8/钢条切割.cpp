#include <iostream>
#include <algorithm>
using namespace std;
int CUT_ROD(int *p,int n)
{
	if (n == 0)//�ݹ�߽硣
		return 0;
	int q = -1,qq;//��Ϊ�����ļ�ֵʼ��Ϊ��ֵ�����Կ��Խ�q��ʼ��Ϊ-1��
	
	for (int i = 1; i <= n; i++)
	{
		cout << n - i<<" ";
		qq = p[i-1]+ CUT_ROD(p, n- i);/*������ֽ�Ϊ��������Ϊn�ĸ����ֽ�Ϊ��߿�ʼһ�Σ��Լ�ʣ��Ĳ��ּ����ֽ�Ľ����*/
		q = max<int>(q, qq);//q���Ǵ洢Ŀǰ���ļ�ֵ��

		cout << "\n";
	}
	return q;
}
int CUT_ROD(int *p,int n,int * r)
{
	if (r[n] >= 0)
		return r[n];
	int q;
	if (n == 0)
		q = 0;
	else {
		q = -1;
		for (int i = 1; i <= n; i++){
			int qq = p[i] + CUT_ROD(p, n - i, r);
			q = max<int>(q, qq);
		}
	}
	r[n] = q;
	return q;
}
//���¶��ϵİ汾
/* �������ʱ��������ģ��С�������⣬Ȼ�����μӴ�������Ĺ�ģ����Ϊ���ϴ��ģ��������ʱ�����ù�ģ��С����Ľ⣬
���Ը��㷨ʹ������r���洢�Ѿ�����������Ľ⣬���������ϴ�����Ľ�ʱ�����������Ѿ����Ĺ�ģ��С��������Ľ⡣*/
int CUT_ROD1(int *p,int n)
{
	//����r��r[n]��¼�ĳ���Ϊn�ĸ�����������档
	int r[11] = { -1,-1,-1, -1, -1, -1, -1, -1, -1, -1, -1 };
	r[0] = 0;//��r[0]��ʼ��Ϊ0,����Ϊ����Ϊ0�ĸ���û�����档
	int q;
	for (int j = 1; j <= n; j++)//��j�����������ÿһ����ģΪj�������⡣
	{
		q = -1;
		for (int i = 1; i <= j; i++)
			q = max<int>(q, p[i] + r[j - i]);//ֱ��ͨ����������Ԫ��r[j-i]����ù�ģj-i��������Ľ⣬�����ؾ��ѵݹ���á�
		r[j] = q;
	}
	return r[n];
}
void test()
{
	int p[11] = { 0,1,5,8,9,10,17,17,20,24,30 };
	int n = 4;
	int r[11] = { -1,-1,-1, -1, -1, -1, -1, -1, -1, -1, -1};
	int ans = CUT_ROD1(p, n);
	int anss= CUT_ROD(p, n,r);
	cout << "ans= " << ans << " \n";
	cout << "anss= " << anss << " \n";
}
void test1()
{
	int a = 8, b = 9;
	int maxx = max<int>(a, b);
	cout << maxx;
}
int main()
{
	test();
	return 0;
}