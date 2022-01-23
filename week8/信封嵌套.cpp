#include<iostream>
#include<algorithm>
using namespace std;
int maxEnvelopes(int envelopes[][2], int n)
{
	int *temp=nullptr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++)
			cout << envelopes[i][j] << " ";
		cout << endl;
	}
	return 0;
}
int ZCxulie(int* p, int n)
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
	int envelopes[12] = { 1,8,2,3,5,4,5,2,6,7,6,4};
	int min = envelopes[0];
	int envelopesl[6]{};
	int j = 1;
	for (int i = 0; i < 6; i++)
		envelopesl[i] = envelopes[j + 2*i];
	for (int i = 0; i < 6; i++)
		cout<<envelopesl[i]<<" ";
	cout << endl;
	cout<<ZCxulie(envelopesl, 6);
}
int main()
{
	test();
	return 0;
}