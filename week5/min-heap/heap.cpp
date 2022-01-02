#include <cstdio>
#include <iostream>
#include "heap.h"
#include <cmath>
#define Infinity 6666
using std::cout;
using std::cin;
Heap::Heap()
{
	heaplength = 0;
	heapsize = 0;
	memset(A, 0, length);
}
void Heap::InitHeap()
{
	cout << "请输入一个无序数组：\n";
	int i = 1;
	cin >> A[i];
	while (A[i] != 0)
	{
		i++;
		++heaplength;
		cin >> A[i];
	}
	heapsize = heaplength;
}
void Heap::MinHeapity(int i)
//默认是结点i破坏了堆序性质。
{
	if (i>int(heapsize/2)||2*i>heapsize) return;//当最后的叶子节点的根节点，是最后一个有左或右孩子的的结点
	int left = 2 * i;
	int right = 2 * i + 1;
	int minmun = 0;
	if (left <= heapsize && A[left] < A[i])	minmun = left;
	//当结点i 的左孩子存在且左孩子小于该结点，则左孩子是较小的那个，否则这个结点是较小的 。
	else minmun = i;
	if (right <= heapsize && A[right] < A[minmun])   minmun = right;//同上
	if (minmun != i) 	swap(A[i], A[minmun]);//当结点i比他其中一个孩子小，就和其中较小的一个孩子换位
	if (minmun == i)     minmun = heapsize;
	//当结点i比他的两个孩子还要小，则说明这个堆肯定是满足堆序性质的。不需要在继续往下了
	MinHeapity(minmun);//继续往下。
}
void Heap::BuildMinHeap()
{
	heapsize = heaplength;
	int i = heaplength / 2;
	//因为MinHeapity函数是默认只是结点i 破坏了堆序性质，所以堆要从下往上建立
	//所以从最后一个结点的根节点，开始往上建立，
	//（如果是叶子结点的话，肯定是满足堆序性质的，因为一个结点肯定是最小堆）
	for (i = heaplength / 2; i >= 1; i--)
		MinHeapity(i);
}
int Heap::HeapMinmun()
{
	return A[1];
}
int Heap::HeapExteractMin()
//去掉并返回S中的具有最小关键字的元素
{
	if (heapsize < 1){
		cout << "heap underflow\n";
		return 0;
	}
	int min = A[1];
	swap(A[1], A[heapsize]);
	heapsize--;
	heaplength--;
	MinHeapity(1);
	return min;
}
//降低结点i的优先级（减小结点i的关键字）
void Heap::HeapUncreaseKey(int i, int key)
{
	if (key > A[i]) {
		cout << "new key is larger than current key!\n";
		return ;
	}
	A[i] = key; 
	while (i > 1 && A[i / 2] > A[i]){
		swap(A[i], A[i / 2]);
		i /= 2;
	}
}
void Heap::MinHeapInsert(int key)
{
	heapsize++;
	heaplength++;
	A[heapsize] = Infinity;
	HeapUncreaseKey(heapsize, key);
}
int Heap::MinHeapDelete(int i)
{
	int del = A[i];
	swap(A[i], A[heapsize]);
	heapsize--;
	heaplength--;
	MinHeapity(i);
	return del;
}

void Heap::ShowHeap()
{
	if (heaplength == 0){
		cout << "堆为空\n";
		return;
	}
	cout << "堆中数据为：\n";
	int i,j,k,l;
	for (i = 1,k=(int)log2(heaplength)+1; i <(int)pow(2,log2(heaplength)+1) && k >= 0; i = i * 2, k--)
	{
		l = k;
		while (l)
		{
			cout << "\t";
			l--;
		}
		for (j = i; j < 2 * i && j <= heaplength; j++)
		{
			cout << A[j];
			if (j != 1) cout << "\t\t";
		}
		cout << "\n";
	}
}
int  Heap::Heapsize()
{
	return heapsize;
}
void Heap::HeapSort()
{
	BuildMinHeap();
	int i = 0;
	for (i = heapsize; i >= 2; i--)
	{
		swap(A[1], A[i]);
		heapsize--;
		MinHeapity(1);
	}
}
void swap(int& a, int& b)
{
	int temp;
	temp = a; a = b; b = temp;
}