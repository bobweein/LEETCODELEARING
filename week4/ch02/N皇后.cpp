//���е�ȫ��������,���N�ʺ�����
#include <cstdio>
#include <iostream>
const int maxn = 11;
int n, P[maxn];//P���±�Ϊ�У������е�Ԫ��Ϊ��
bool hashTable[maxn] = { false };//��¼����x�Ƿ���P��
//����ǰ���еĵ�index��
void generateP(int index)
{
	if (index == n + 1) { //�ݹ�߽磬�Ѿ��������1-n�У��ܵ������һ���ǺϷ���
		for (int i = 1; i <= n; i++) {
			printf(" %d " , P[i]);//�����ǰ
		}
		printf("\n");
		return;
	}
	for (int x = 1; x <= n; x++)//��٣��ҵ��ܹ����ڵ�index�е�x
	{
		if (hashTable[x] == false) //�����x��û�лʺ�
		{//�����x�л�û�лʺ�
			bool flag = true; //flag Ϊtrue ��ʾ��ǰ�ʺ󲻻��֮ǰ�Ļʺ��ͻ�������Ǽ���
			for (int pre = 1; pre < index; pre++)//����֮ǰ1��index-1�еĻʺ󣬼��x�Ƿ��ܷ��ڵ�index��
			{//��index �еĻʺ���к�Ϊx����pre �еĻʺ���к�ΪP[pre]
				if (abs(index - pre) == abs(x - P[pre]))
				{
					flag = false;
					break;
				}
			}
			if (flag)//���x���Է��ڵ�index�У�����ǰ������г�ͻ
			{
				P[index] = x;//��x���ڵ�index��
				hashTable[x] = true;//��ǵ�x���Ѿ��лʺ���
				generateP(index + 1);//ȥ����index+1��
				hashTable[x] = false;//�ݹ���ϣ���ԭ��x��ΪΪռ�á�
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