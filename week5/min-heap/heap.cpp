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
	cout << "������һ���������飺\n";
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
//Ĭ���ǽ��i�ƻ��˶������ʡ�
{
	if (i>int(heapsize/2)||2*i>heapsize) return;//������Ҷ�ӽڵ�ĸ��ڵ㣬�����һ��������Һ��ӵĵĽ��
	int left = 2 * i;
	int right = 2 * i + 1;
	int minmun = 0;
	if (left <= heapsize && A[left] < A[i])	minmun = left;
	//�����i �����Ӵ���������С�ڸý�㣬�������ǽ�С���Ǹ��������������ǽ�С�� ��
	else minmun = i;
	if (right <= heapsize && A[right] < A[minmun])   minmun = right;//ͬ��
	if (minmun != i) 	swap(A[i], A[minmun]);//�����i��������һ������С���ͺ����н�С��һ�����ӻ�λ
	if (minmun == i)     minmun = heapsize;
	//�����i�������������ӻ�ҪС����˵������ѿ϶�������������ʵġ�����Ҫ�ڼ���������
	MinHeapity(minmun);//�������¡�
}
void Heap::BuildMinHeap()
{
	heapsize = heaplength;
	int i = heaplength / 2;
	//��ΪMinHeapity������Ĭ��ֻ�ǽ��i �ƻ��˶������ʣ����Զ�Ҫ�������Ͻ���
	//���Դ����һ�����ĸ��ڵ㣬��ʼ���Ͻ�����
	//�������Ҷ�ӽ��Ļ����϶�������������ʵģ���Ϊһ�����϶�����С�ѣ�
	for (i = heaplength / 2; i >= 1; i--)
		MinHeapity(i);
}
int Heap::HeapMinmun()
{
	return A[1];
}
int Heap::HeapExteractMin()
//ȥ��������S�еľ�����С�ؼ��ֵ�Ԫ��
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
//���ͽ��i�����ȼ�����С���i�Ĺؼ��֣�
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
		cout << "��Ϊ��\n";
		return;
	}
	cout << "��������Ϊ��\n";
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