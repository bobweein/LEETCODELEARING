#include <iostream>
#include <cmath>
#include <time.h>
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//�˴��ȼ���if(power%2==1)��ָ��λ����ʱ
            result = result * base % 1000;//�����1000����Ϊ���������̫���ˣ�ֻȡ������������λ
        }
        power >>= 1;//�˴��ȼ���power=power/2
        base = (base * base) % 1000;//�˴�������ƽ��
    }
    return result;
}
int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    clock_t start, finish;
    //clock_tΪCPUʱ�Ӽ�ʱ��Ԫ��
    long long base, power;
    cin >> base >> power;
    start = clock();
    //clock()�������ش�ʱCPUʱ�Ӽ�ʱ��Ԫ��
    cout << fastPower(base, power) << endl;
    finish = clock();
    //clock()�������ش�ʱCPUʱ�Ӽ�ʱ��Ԫ��
    cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
    //finish��start�Ĳ�ֵ��Ϊ�������л��ѵ�CPUʱ�ӵ�Ԫ�������ٳ�ÿ��CPU�ж��ٸ�ʱ�ӵ�Ԫ����Ϊ�����ʱ
    return 0;

}