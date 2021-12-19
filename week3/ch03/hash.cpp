///时间复杂度为n
#include <iostream>
#include <cctype>
#define HASHSIZE 37//散列表数组的长度
bool hashTable[HASHSIZE]{false};
int HashFun(char key);
void InitHash(const char key);
int HashFun(char key)//散列函数
{
	int value=0;
	if (isdigit(key))
		value = (int)key - 48;//数字0-9的ascll的十进制是从48开始的，将0-9放在散列表中下标为0-9的位置
	else if (key == '_')
		value = (int)key - 22;//空格的ascll的十进制是32，将他放在散列表中下标为10的位置
	else if (isalpha(key))
		value=11+ toupper(key)-'A';//将字母（不区分大小写）放在散列表中下标为11到36的位置
	return value;
}
void InitHash(const char key)
{
	
		hashTable[HashFun(key)] = true;
}
int main()
{
	using namespace std;
	char arr[100]="7_This_is_a_test";
	char arr1[100] = "_hs_s_a_es";
	char arr2[100];
	cout << "应该要输入的一段文字:"<<arr<<endl;
	cout << "实际被输出的文字：" << arr1<<endl;
	int i = 0,j=0;
	while (arr1[i] != '\0')
	{
		InitHash(arr1[i]);
		i++;
	}
	i = 0;
	cout << "有故障的按键：";
	while (arr[i] != '\0')
	{
		if (!hashTable[HashFun(arr[i])])//如果这个按键是故障的
		{
			arr2[j] = arr[i];//将故障的按键放到数组arr2中，但是会将重复的也放进去。
			if (!isalpha(arr2[j])) cout << (char)arr2[j];//先输出这个放到数组arr2中的故障按键
			else   cout << (char)toupper(arr2[j]);
			InitHash(arr2[j]);
			//输出的故障按键后，假装这个按键又”变好“了，这样下次在遇到这个故障的按键的时候就不会重复输出了。
			j++;
		}
		i++;
	}

	return 0;
}
