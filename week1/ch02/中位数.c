//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//你可以假设 nums1 和 nums2 不会同时为空。
//时间复杂度为O(log(m+n))
#include <iostream>
using namespace std;
int main()
{
	int arr1[8]={1,3,7,9,17,25,33,55};
	int arr2[10] = { 2,4,8,12,18,22,66,88,99,100 };
	int m = 8, n = 10;
	int  *arr = new int[m + n];
	int k = 0; int i=0, j=0;
	for (k = 0; k < m + n; k++)
	{
		if (i < m && j < n)
		{
			if (arr1[i] < arr2[j])
				arr[k] = arr1[i++];
			else
				arr[k] = arr2[j++];
	    }
        else if (i < m)
			arr[k] = arr1[i++];
		else if(j<n)
			arr[k] = arr2[j++];
		
	} 
	cout << "排好序的数组为：\n";
	for (i = 0; i < k; i++)
		cout << arr[i] << "  ";
	cout << endl;
	int midnum=0;
	midnum = arr[(m + n) / 2];
	cout << "中位数为：" << midnum << endl;
	return 0;


}
