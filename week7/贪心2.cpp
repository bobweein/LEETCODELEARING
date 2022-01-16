#include <iostream>
using std::cout;
using std::cin;
int main()
{
	int arr[10]{};
	int count[10]{};
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		count[arr[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 0) {//最高位数字在1-9之间选取最小的。
			for(int j=1;j<10;j++)
				if (count[j] != 0) {
					count[j]--;
				    cout<< j<<"  ";
					break;
				}
		}
		else {//出最高位外，其他位上一次选取0-9之间最小的。
			for (int j = 0; j < 10; j++) {
				if (count[j] != 0) {
					count[j]--;
					cout<< j<<"  ";
					break;
				}
			}
		}
	}
	
	cout << std::endl;
	return 0;
}