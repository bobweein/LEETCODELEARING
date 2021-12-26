//序列的全排列问题,解决N皇后问题
#include <cstdio>
#include <iostream>
const int maxn = 11;
int n, P[maxn];//P的下标为列，数组中的元素为行
bool hashTable[maxn] = { false };//记录整数x是否在P中
//处理当前排列的第index列
void generateP(int index)
{
	if (index == n + 1) { //递归边界，已经处理完的1-n列，能到这里就一定是合法的
		for (int i = 1; i <= n; i++) {
			printf(" %d " , P[i]);//输出当前
		}
		printf("\n");
		return;
	}
	for (int x = 1; x <= n; x++)//穷举，找到能够放在第index列的x
	{
		if (hashTable[x] == false) //如果第x行没有皇后
		{//如果第x行还没有皇后
			bool flag = true; //flag 为true 表示当前皇后不会和之前的皇后冲突，这里是假设
			for (int pre = 1; pre < index; pre++)//遍历之前1到index-1列的皇后，检查x是否能放在第index列
			{//第index 列的皇后的行号为x，第pre 列的皇后的行号为P[pre]
				if (abs(index - pre) == abs(x - P[pre]))
				{
					flag = false;
					break;
				}
			}
			if (flag)//如果x可以放在第index列，不会前面的列有冲突
			{
				P[index] = x;//把x放在第index列
				hashTable[x] = true;//标记第x行已经有皇后了
				generateP(index + 1);//去处理index+1列
				hashTable[x] = false;//递归完毕，还原第x行为为占用。
			}
		}
	}

}
int main()
{
	n = 5;
	generateP(1);
	return 0;
}