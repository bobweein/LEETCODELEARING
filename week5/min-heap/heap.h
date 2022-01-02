#ifndef _HEAP_H
#define _HEAP_H
class Heap
{
private:
	static const int length=100;
	//注意heapsize 和heaplength 的计算会不会混乱
	int heapsize;
	int heaplength;
	int A[length];
public:
	Heap();
	void InitHeap();
	void MinHeapity(int i);
	void BuildMinHeap();
	void ShowHeap();
	int  Heapsize();

	//poiority queue methoy
	int HeapMinmun();
	int HeapExteractMin();
	void HeapUncreaseKey(int i,int key);
	void MinHeapInsert(int key);
	int MinHeapDelete(int i);
	//queue
	
	// stack
    //Heap sort 
	void HeapSort();
	
};
void swap(int& a, int& b);
#endif
