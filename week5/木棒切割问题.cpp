/* ģ���и����⣺����N��ľ�������Ⱦ���֪������ϣ��ͨ���и��������õ�
����K�γ�����ȵ�ľ�������ȱ���Ϊ������������Щ������ȵ�ľ������ж೤��*/
// ʹ�ö��ַ�
#include <iostream>
const int k=3;//���׶�ľ���ĸ�����
const int  K=7;//׼����k��ľ���׶γ�K��һ������Сľ����
int f(int* arr, int L);
int erfen(int* arr);
int erfen(int *arr)
{
	int i, num=0,sum=0;
	for (i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	int left = 1;//�سɵĵȳ���ľ������С����
	int right = sum / K;//�سɵĵȳ���ľ������󳤶�
	int mid=0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		//��������Ͻ糬��int�����ݷ�Χ��һ�룬��ô������ѯԪ�ص�λ�ýϿ���ʱ��
		//��䣨left+right��/2�е�(left+right)���ܻᳬ��int���������磬��ʱһ��ʹ��
		//mid=left+(right-left)/2��������������Ա��������
		// Ŀ�����ҵ���һ��ʹf(L)����С��0��L������ڽ����ֵ��һ�����ܵõ���Ҫ�Ĵ�
		//��Ϊ����f(L)���ǹ���L�ĵ����ݼ�������
		if(f(arr,mid)>=0){
			//��f(mid)>=0ʱ����֪����һ��ʹf(L)��L��mid����������[mid+1,right]��
			left = mid + 1;
		}
		if (f(arr, mid) < 0) {
			//��F(mid)<0ʱ����֪����һ��ʱf(L)��L��mid������mid��ߵ���������[left,mid]��
			right = mid;
		}
	}
	return left - 1;	
}
int f(int* arr, int L)
{
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += (arr[i] /L);
	}
	return sum - K;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "������ľ���ĸ�����";
	cout<<k<<endl;
	int* arr = new int[k];
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	cout << "����Щľ�������и��K�� K= ";
	cout << K<<endl;
	int L = erfen(arr);
	cout << "�����ΪL��" << L;
	delete[]arr;
	return 0;


}