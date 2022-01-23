#include <iostream>
#include <algorithm>
using namespace std;
/* dp[i]��ʾΪnums[i]�������β�������������еĳ��ȡ�
base case: dp[i]��ʼֵΪ1����Ϊ��nums[i]��β�����������������Ҫ�������Լ���
�㷨�Ͻ��Ĺ��̾��Ǵ�i=0��ʼ����dp���飬ͨ��dp[0.....i-1]���Ƶ�dp[i]
����������壬�������յĽ��Ӧ����dp���������ֵ��
*/
int ZCxulie(int* p,int n)
{
	int* dp = new int[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i] > p[j])
				dp[i] = max<int>(dp[i], dp[j] + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		res = max<int>(res, dp[i]);
	return res;
}
void test()
{
	int p[8] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int n = 8;
	cout<<ZCxulie(p, n)<<"\n";

}
int main()
{
	test();
	return 0;
}