#include <iostream>
#include <cmath>
#include <time.h>
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)当指数位奇数时
            result = result * base % 1000;//这里除1000是因为求出来的数太大了，只取这个数的最后三位
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 1000;//此处将底数平方
    }
    return result;
}
int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    long long base, power;
    cin >> base >> power;
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << fastPower(base, power) << endl;
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;

}