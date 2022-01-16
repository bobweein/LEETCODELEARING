//���һ�������㷨���Կ�������Ϊ���㷨��ģ�͡�
#include<iostream>
#include <ctime>
int RandomizeSelect(int* A, int p, int r, int i);
int RandomizedPartition(int* A, int p, int r);
void Swap(int & a, int &b);
int Partition(int* A, int p, int r);
int Partition(int* A, int p, int r)
{
	int x = A[r];//A[r]Ϊ��Ԫ��
	int i = p - 1,j;
	for (j = p; j < r; j++)
		if (A[j] <= x) {
			i = i + 1;
			Swap(A[i], A[j]);
		}
	Swap(A[i + 1], A[r]);
	return (i + 1);
}
int RandomizedPartition(int* A, int p, int r)
{
	srand(time(0));
	int i = int( rand() / RAND_MAX * (r - p+1) + p);
	Swap(A[r],A[i]);
	return Partition(A, p, r);
}

int RandomizeSelect(int* A, int p, int r, int i)
{
	if (p == r)//������ֻ��һ��Ԫ�ء�
		return A[p];
	int q ;
	q = RandomizedPartition(A, p, r);//������Ԫ��
	int k = q-p+1;//��������A��С�ڵ�����Ԫ��Ԫ�ظ�����
	if (i == k)//˵���ҵ���iС�����ˡ�
		return A[q];
	//������С�ڵ�����Ԫ��Ԫ�صĸ�������iʱ����Ϊ��Ԫ��ߵ���һ��С��
	//��Ԫ�����Ե�iС��������Ԫ����ߡ�
	else if (i < k)
		return RandomizeSelect(A, p, q - 1, i);
	//��i>kʱ��˵��������С�ڵ�����Ԫ��Ԫ�صĸ���С��i ,���Ե�iС��Ԫ��һ����
	//��Ԫ���Ҷˡ����Ե���Ԫ���Ҷ˲��ҡ�ע����ʱ�������ҵ�iС���ˣ���Ϊ����
	//������Ԫ���ұ߲��ң�����Ԫ������Ѿ���k-1��С����Ԫ�������������ұ���Ӧ��
	//ʱ������Ԫ�Ҷ˵ĵ�i-k��С��Ԫ�ء�
	else return RandomizeSelect(A, q + 1, r, i-k);
}
void Swap(int& a, int& b)
{
	int item;
	item = a;
	a = b;
	b = item;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int A[8] = { 2,8,7,1,3,5,6,4 };
	cout << "������i,��ʾ�����������е�iС����;\n";
	int i;
	cin >> i;
	int ans=RandomizeSelect(A, 0, 7, i);
	cout << "�� "<<i<<" С������Ϊ�� " << ans << endl;
	return 0;
}