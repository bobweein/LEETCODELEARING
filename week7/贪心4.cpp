/*̰�Ĳ���
1.�������м���Ԫ��0��Ȼ��������ɴ�С���У�����0�ͽ�����ֳ��������֡�
2.ѡȡ����������������еĴ������ˣ���������ͬ��
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
	const int m = 5;//������Ԫ�صĸ�����һ
	const int n = 5;
	int arr[m] = { -2,-3,3,4,0 };//��Ϊ�����д���0ʱ�������û��Ӱ�졣
	int arr2[n] = { -2,-1,2,3,0 };
	sort(arr, arr + m, cmp);//Ϊʲôsort������ͬʱ��Ҫͷ�ļ�<algorithm>,ͬʱ����Ҫstd
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