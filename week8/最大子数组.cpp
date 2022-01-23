#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSubArray(int* nums, int n)
{
	if (n == 0)
		return 0;
	int* dp = new int[n];
	//base case:第一个元素前面没有子数组。 
	dp[0] = nums[0];
	for (int i = 1; i < n; i++)
		dp[i] = max<int>(nums[i], nums[i] + dp[i - 1]);
	int res = *max_element(dp,dp+n);
	return res;
}
void test()
{
	int nums[7] = { -3,1,3,-1,2,-4,2 };
	int n = 7;
	cout<<maxSubArray(nums,n);
}
int main()
{
	test();
	return 0;
}