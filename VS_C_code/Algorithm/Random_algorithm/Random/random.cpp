#include <iostream>
#include <random>
#include <ctime>

using namespace std;

default_random_engine e;

// 得到 a~b 之间的随机数
int GetRandom(int a, int b) {
    uniform_int_distribution<unsigned> u(a, b);
    return u(e);
}

int main()
{
    // 初始化随机种子
    e.seed(time(0));
    return 0;
}