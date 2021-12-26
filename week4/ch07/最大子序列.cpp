#include <iostream>
const int  Infinity =6666;
int Crossing(int* A, int low, int mid, int high);
int Findmax(int* A, int low, int high);
int Crossing(int* A, int low, int mid, int high)
{
	int left_sum = -Infinity;
	int sum = 0;
	int i;
	for (i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}
	int right_sum = -Infinity;
	sum = 0;
	for (i = mid+1; i <= high; i++)
	{
		sum += A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
		}
	}
	return left_sum + right_sum;
}
int Findmax(int* A, int low, int high)
{
	if (high == low)
		return A[low];
	else
	{
		int mid = (low + high) / 2;
		int left_max = 0, right_max = 0, cross_max = 0;
		left_max = Findmax(A, low, mid);
		right_max = Findmax(A, mid + 1, high);
		cross_max = Crossing(A, low, mid, high);
		if (left_max >= right_max && left_max >= cross_max)
			return left_max;
		else if (right_max >= left_max && right_max >= cross_max)	
			return right_max;
		else
			return cross_max;
	}
}
int main()
{
	int A[10] = { -1,-2,-3,-4,-5,-6,-7,-2,-8,-10 };
	int MaxUnderArray = Findmax(A, 0, 9);
	std::cout << "MaxUnderArray: " << MaxUnderArray;
	return 0;
}