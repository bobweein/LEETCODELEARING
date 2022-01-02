/* 模板切割问题：给出N根木棒，长度均已知，现在希望通过切割他们来得到
至少K段长短相等的木棒（长度必须为整数），问这些长度相等的木棒最长能有多长？*/
// 使用二分法
#include <iostream>
const int k=3;//待阶段木棍的根数。
const int  K=7;//准备将k根木棍阶段成K根一样长的小木条。
int f(int* arr, int L);
int erfen(int* arr);
int erfen(int *arr)
{
	int i, num=0,sum=0;
	for (i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	int left = 1;//截成的等长的木棍的最小长度
	int right = sum / K;//截成的等长的木棍的最大长度
	int mid=0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		//如果二分上界超过int型数据范围的一半，那么当欲查询元素的位置较靠后时，
		//语句（left+right）/2中的(left+right)可能会超过int而导致外溢，此时一般使用
		//mid=left+(right-left)/2来替代上面的语句以避免溢出。
		// 目的是找到第一个使f(L)函数小于0的L，最后在将这个值减一，就能得到想要的答案
		//因为函数f(L)，是关于L的单调递减函数；
		if(f(arr,mid)>=0){
			//当f(mid)>=0时，便知道第一个使f(L)的L在mid的右子区间[mid+1,right]中
			left = mid + 1;
		}
		if (f(arr, mid) < 0) {
			//当F(mid)<0时，便知道第一个时f(L)的L在mid处或者mid左边的左子区间[left,mid]中
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
	cout << "请输入木棒的根数：";
	cout<<k<<endl;
	int* arr = new int[k];
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	cout << "将这些木棒至少切割成K段 K= ";
	cout << K<<endl;
	int L = erfen(arr);
	cout << "最长可以为L：" << L;
	delete[]arr;
	return 0;


}