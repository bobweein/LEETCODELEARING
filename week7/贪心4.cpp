/*贪心策略
1.往数组中加入元素0，然后对数组由大到小排列，这样0就将数组分成两个部分。
2.选取两数组的正数部分中的大的数相乘，负数部分同理。
*/
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b);
bool cmp(int a, int b)
{
		return a > b;
}
int main()
{
	const int m = 5;//集合中元素的个数加一
	const int n = 5;
	int arr[m] = { -2,-3,3,4,0 };//因为集合中存在0时，对求解没有影响。
	int arr2[n] = { -2,-1,2,3,0 };
	sort(arr, arr + m, cmp);//为什么sort函数，同时需要头文件<algorithm>,同时还需要std
	for (int i = 0; i < m; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
	sort(arr2, arr2 + n, cmp);
	for (int j = 0; j < n; j++)
		cout << arr2[j] << " ";
	cout << "\n";
	int i = 0, j = 1;
	int ans = 0;
	while (1) {
		if (arr[i] > 0 && arr2[i] > 0) {
			ans += arr[i] * arr2[i];
			i++;
		}
		else break;
	}
	while (1) {
		if (arr[m- j] < 0 && arr2[n- j] < 0) {
			ans += (arr[m- j] * arr2[n- j]);
			j++;
		}
		else break;
	}
	cout << ans;
	return 0;
}