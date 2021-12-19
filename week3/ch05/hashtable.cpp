#include <cstdio>
const int maxn = 100;
int hashTable[maxn] = { 0 };
int main()
{
	int n, m, x;
	printf("请输入hashTable中元素的个数 n 要查找的元素的个数m\n");
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		hashTable[x]++;
	}
	for (int i = 0; i < m; i++)
	{
		printf("请输入要查找的元素的值:");
		scanf_s("%d", &x);
		printf("要查找的元素在hashTable 中的个数：%d\n\n", hashTable[x]);
	}
	return 0;
}
