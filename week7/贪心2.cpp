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
		if (i == 0) {//���λ������1-9֮��ѡȡ��С�ġ�
			for(int j=1;j<10;j++)
				if (count[j] != 0) {
					count[j]--;
				    cout<< j<<"  ";
					break;
				}
		}
		else {//�����λ�⣬����λ��һ��ѡȡ0-9֮����С�ġ�
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