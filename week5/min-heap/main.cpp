#include <iostream>
#include "heap.h"
int main()
{
	Heap heap1;
	heap1.InitHeap();
	heap1.BuildMinHeap();
	heap1.ShowHeap();
	heap1.HeapExteractMin();
	heap1.ShowHeap();
	heap1.HeapUncreaseKey(2, 1);
	heap1.ShowHeap();
	heap1.HeapUncreaseKey(7, 2);
	heap1.ShowHeap();
	heap1.MinHeapInsert(6);
	heap1.ShowHeap();
	heap1.MinHeapDelete(2);
	heap1.ShowHeap();
	Heap heap2;
	heap2.InitHeap();
	heap2.HeapSort();
	heap2.ShowHeap();
	return 0;

}