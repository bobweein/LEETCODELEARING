/*�˴���̰�Ĳ���Ϊ��
1. Ѱ�Ҿ��뵱ǰ����վ��������ͼ۵��ڵ�ǰ�ļ���վ����Ϊk�����ڵ�ǰ����վ��ǡ���ܹ��������վk����
Ȼ��ǰ���ü���վ��
2. ���Ѱ�Ҳ����ͼ۵��ڵ�ǰ�ͼ۵ļ���վ����Ѱ���ͼ���͵ļ���վ���ڵ�ǰ����վ�����͡�Ȼ��ǰ������վk
������û�и����ͼ۵ļ���վʱ��ǰ���ͼ۾����ܵ͵ļ���վ����
3.������״̬�¶��Ҳ����ܵ���ļ���վ������Զ�ܵ���ľ���Ϊ��ǰ����վ�ľ����������״̬���ܹ�ǰ����
�����룬�����㷨*/
#include<iostream>
#include <algorithm>
const int INF = 1000000;
using namespace std;
struct GasStation
{
	double price;
	int length;
};
bool cmp(GasStation a, GasStation b)
{
	return a.length < b.length;
}
void  tanxin(GasStation *gas, double Cmax, double D, double Dvag, int n);
void tanxin(GasStation *gas, double Cmax, double D, double Dvag, int n)
{
	int now = 0;//��ǰ���ڼ���վ�ı�š�
	double ans = 0, nowTank = 0, Max = Cmax * Dvag;//�ܻ��ѣ���ǰ��������������ʻ���롣
	while (now < n) {//ÿ��ѭ����ѡ����һ������Ҫ����ļ���վ��
		//ѡ���ӵ�ǰ����վ�����ܵ��ﷶΧ�ڵĵ�һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ��
		//���û�е��ڵ�ǰ�ͼ۵ļ���վ����ѡ��ѡ��۸�����Ǹ���
		int k = -1;//�ͼ���͵ļ���վ�ı�š�
		double  priceMin = INF;//����ͼۡ�
		//forѭ���ĵڶ���ѭ������������������ʱ���ܹ��������Զ�����ڵļ���վ��
		for (int i = now + 1; i <= n && gas[i].length - gas[now].length <= Max; i++) {
			if (gas[i].price < priceMin) {//����ͼ۱ȵ�ǰ�ͼ۵͡�
				priceMin = gas[i].price;//��������ͼۡ�
				k = i;
			}
			//����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ��ֱ���ж�ѭ����
			if (priceMin < gas[now].price) {
				break;
			}
			//���û���ͼ۸��͵ļ���վʱ��ǰ���ͼ۾����ܵ͵ļ���վ���������Ҫ��������������
		}
		if (k == -1) break;//����״̬���޷��ҵ�����վ���˳�ѭ����������
		//need Ϊnow ��k��Ҫ��������
		double need = (gas[k].length - gas[now].length) / Dvag;
		if (priceMin < gas[now].price) {//�������վk���ͼ۵��ڵ�ǰ���ͼ�
			//ֻ���㹻�������վk���͡�
			if (nowTank < need) {
				ans += (need - nowTank) * gas[now].price;//������Ҫ��
				nowTank = 0;//�������վk������������Ϊ0.
			}
			else //�����ǰ��������need��
				nowTank -= need;//ֱ�ӵ������վk
		}
		else {//�������վk���ͼ۸��ڵ�ǰ���ͼ�
			ans += (Cmax - nowTank) * gas[now].price;
			//�������վk�������ڵ�����ΪCmax-need
			nowTank = Cmax - need;
		}
		now = k;//�򵽼���վk,�����²�ѭ����
	}
	if (now == n) //�ܵ��ﰡ�յ㡣
		cout << "ans=" << ans;
	else//���ܵ����յ㡣
		cout << "the maximun travel distance= " << gas[now].length + Max;
}
int main()
{
	double Cmax = 50;
	double D = 1300;
	double Dvag = 12;
	const int n = 9;
	GasStation gas[n] = { {6.00,1250},{7.00,600},{7.00,150},{7.10,0},
		{7.20,200},{7.50,400},{7.30,1000},{6.85,300},{0.00,1300} };
	sort(gas, gas + n, cmp);
	if (gas[0].length != 0)
		cout << "ԭ�㴦û�м���վ���޷�����\n";
	else 
		 tanxin(gas, Cmax, D, Dvag, n);
	return 0;
}