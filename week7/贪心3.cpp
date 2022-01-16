/*此处的贪心策略为，
1. 寻找距离当前加油站最近的且油价低于当前的加油站（记为k），在当前加油站加恰好能够到达加油站k的油
然后前往该加油站。
2. 如果寻找不到油价低于当前油价的加油站，则寻找油价最低的加油站，在当前加油站加满油。然后前往加油站k
（即在没有更低油价的加油站时，前往油价尽可能低的加油站。）
3.在满油状态下都找不到能到达的加油站，则最远能到达的距离为当前加油站的距离加上满油状态下能够前进的
最大距离，结束算法*/
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
	int now = 0;//当前所在加油站的编号。
	double ans = 0, nowTank = 0, Max = Cmax * Dvag;//总花费，当前油量，及满油行驶距离。
	while (now < n) {//每次循环将选出下一个而需要到达的加油站。
		//选出从当前加油站满油能到达范围内的第一个油价低于当前油价的加油站。
		//如果没有低于当前油价的加油站，则选择选择价格最低那个。
		int k = -1;//油价最低的加油站的编号。
		double  priceMin = INF;//最低油价。
		//for循环的第二个循环控制条件，控制了时在能够到达的最远距离内的加油站。
		for (int i = now + 1; i <= n && gas[i].length - gas[now].length <= Max; i++) {
			if (gas[i].price < priceMin) {//如果油价比当前油价低。
				priceMin = gas[i].price;//更新最低油价。
				k = i;
			}
			//如果找到第一个油价低于当前油价的加油站，直接中断循环。
			if (priceMin < gas[now].price) {
				break;
			}
			//如果没有油价更低的加油站时，前往油价尽可能低的加油站。这里很重要！！！！！！。
		}
		if (k == -1) break;//满油状态下无法找到加油站，退出循环输出结果。
		//need 为now 到k需要的油量。
		double need = (gas[k].length - gas[now].length) / Dvag;
		if (priceMin < gas[now].price) {//如果加油站k的油价低于当前的油价
			//只买足够到达加油站k的油。
			if (nowTank < need) {
				ans += (need - nowTank) * gas[now].price;//补足需要。
				nowTank = 0;//到达加油站k后油箱内油量为0.
			}
			else //如果当前油量超过need，
				nowTank -= need;//直接到达加油站k
		}
		else {//如果加油站k的油价高于当前的油价
			ans += (Cmax - nowTank) * gas[now].price;
			//到达加油站k后邮箱内的油量为Cmax-need
			nowTank = Cmax - need;
		}
		now = k;//打到加油站k,进入下层循环。
	}
	if (now == n) //能到达啊终点。
		cout << "ans=" << ans;
	else//不能到达终点。
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
		cout << "原点处没有加油站！无法启动\n";
	else 
		 tanxin(gas, Cmax, D, Dvag, n);
	return 0;
}