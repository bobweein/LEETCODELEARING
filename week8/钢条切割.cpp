#include <iostream>
#include <algorithm>
using namespace std;
int CUT_ROD(int *p,int n)
{
	if (n == 0)//递归边界。
		return 0;
	int q = -1,qq;//因为钢条的价值始终为正值，所以可以将q初始化为-1；
	
	for (int i = 1; i <= n; i++)
	{
		cout << n - i<<" ";
		qq = p[i-1]+ CUT_ROD(p, n- i);/*将问题分解为：将长度为n的钢条分解为左边开始一段，以及剩余的部分继续分解的结果。*/
		q = max<int>(q, qq);//q总是存储目前最大的价值。

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
//自下而上的版本
/* 求解问题时，先求解规模最小的子问题，然后依次加大子问题的规模，因为求解较大规模的子问题时，会用规模较小问题的解，
所以该算法使用数组r来存储已经求解的子问题的解，所以在求解较大问题的解时，可以利用已经求解的规模较小的子问题的解。*/
int CUT_ROD1(int *p,int n)
{
	//数组r中r[n]记录的长度为n的钢条的最大收益。
	int r[11] = { -1,-1,-1, -1, -1, -1, -1, -1, -1, -1, -1 };
	r[0] = 0;//将r[0]初始化为0,是因为长度为0的钢条没有收益。
	int q;
	for (int j = 1; j <= n; j++)//对j按照升序求解每一个规模为j的子问题。
	{
		q = -1;
		for (int i = 1; i <= j; i++)
			q = max<int>(q, p[i] + r[j - i]);//直接通过访问数组元素r[j-i]来获得规模j-i的子问题的解，而不必惊醒递归调用。
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