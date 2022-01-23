#include <iostream>
#include <algorithm>
using namespace std;
/* dp[i]表示为nums[i]这个数结尾的最长最递增子序列的长度。
base case: dp[i]初始值为1，因为以nums[i]结尾的最长递增子序列起码要包含他自己。
算法严谨的过程就是从i=0开始遍历dp数组，通过dp[0.....i-1]来推导dp[i]
根据这个定义，我们最终的结果应该是dp数组中最大值。
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