#include <iostream>
#define other 100
int maxn = 0;//六个字母中最多的字母的个数。
int HashTable[6]{ 0 };
int HashFun(char key);
void InitHash(char key);
int HashFun(char key)
{
	int a;
	switch (key)
	{
	case 'P':
		a = 0; break;
	case 'A':
		a = 1; break;
	case 'T':
		a = 2; break;
	case 'e':
		a = 3; break;
	case 's':
		a = 4; break;
	case 't':
		a = 5; break;
	default:
		a = other; break;
	}
	return a;
}
void InitHash(char key)
{
	int value = 0,r=0,temp=0;
	value = HashFun(key);
	if (value != other)
	{
		r=++HashTable[value];
		if (maxn < r)
			maxn = r;
	}
}
int main()
{
	
	char arr[100] = "redlesPayBestPATTopTeePHPereatitAPPT";
	char arr1[6] = { 'P','A','T','e','s','t' };
	int i = 0;
	while (arr[i] != '\0')
	{
		InitHash(arr[i]);
		i++;
	}
	int j = 0; char temp;
	using std::cout;
	for (i = 0; i < maxn; i++)
	{
		for (j = 0; j < maxn; j++)
		{
			temp = HashTable[j];
			if (temp > 0)
				cout << (char)arr1[j] << " ";
			HashTable[j]--;
		}
	}
	return 0;
}