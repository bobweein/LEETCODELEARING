#include <iostream>
#define SUCCESS 1
#define UNSUCCESS 0
#define NULLKEY 3000
#define HASHSIZE 12
typedef struct
{
	int* elem;//数据元素存储基址，动态分配内存
	int count;//当前数据元素个数
}Hashtable;
int m = 0;//散列表长
Hashtable* Inithashtable(Hashtable* H)//初始化哈希表
{
	int i;
    m = HASHSIZE+1;
	H->count = m;
	H->elem = new int [m];
	for (i = 0; i < m; i++)
		H->elem[i] = NULLKEY;
	for (i = 0; i < HASHSIZE+1; i++)
		std::cout << H->elem[i] << "  ";
	std::cout << "\n";
	return H;
}
int Hash(int key)
{
	return key % HASHSIZE;
}
void InsertHash(Hashtable* H, int key)
{
	int addr = Hash(key);
	while (H->elem[addr] != NULLKEY)
		addr = (addr + 1) % m;
	H->elem[addr] = key;
}
int SearchHash(Hashtable* H, int  key)//查找Hashtable中是否有这个元素，如果有返回地址
{
	int addr;
	 addr = Hash(key);
	while (H->elem[addr] != key )
	{
		addr = (addr + 1) % m;
		if (H->elem[addr] == NULLKEY)
			return NULLKEY;
	}
	return addr;
}
int main()
{
	int i = 0;
	Hashtable T = { &m,0 };
	Hashtable *H= &T ;
	H=Inithashtable(H);
	std::cout << H->count<<std::endl;
	int find =63 , key = 0; int xiabiao1 = 0;
	int xiabiao2 = 0;
	char arr[HASHSIZE] ={12,25,38,15,16,29,78,67,56,21,22,47};
	for (i = 0; i < HASHSIZE; i++)
	{
		InsertHash(H, arr[i]);
		for (int j = 0; j < HASHSIZE+1; j++)
			std::cout << H->elem[j] << "  ";
		std::cout << "\n";
	}
	for (i = 0; i < HASHSIZE; i++)
	{
		key = find - H->elem[i];
		xiabiao1=SearchHash(H, key);
		if (xiabiao1 != NULLKEY) 
		{
			xiabiao2 = i;
			std::cout << "这两个数的下标为：" << xiabiao1 << "  " << xiabiao2 << std::endl;
			std::cout << "这两个数分别为：" << H->elem[xiabiao1] << "  " << H->elem[xiabiao2] << std::endl;
			break;
		}
	}
	return 0;
}
