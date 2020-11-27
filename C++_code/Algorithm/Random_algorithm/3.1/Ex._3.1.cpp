/** 
    a mod b = ( (a % b) + b ) % b
    % 出来的数有正有负，符号取决于左操作数
    而mod只能是正
**/
#include<iostream>
#include<cstdlib>
#include<random>
#include<ctime>
#include<cmath>

using namespace std;

int mod(int a, int b) // 计算a mod b
{
    return ((a%b) + b) % b;
}

// 计算满足 a = g^x mod p 的x，无解时返回p
int dlog(int g, int p, int a)
{
    int x = 0, y = 1;
    while(x != p && a != mod(y,p))
    {
        x ++;
        y = y*g; // 计算 y = g^x 
    }
    return x;
}

// 确定性求解算法对应的Sherwood算法
int dlogRH(int g, int p, int a)
{
    default_random_engine e(time(0)); // 生成种子
    uniform_int_distribution<int> u(0,p-2); // 生成 0 ~ p-2 闭区间中的整数

    int r = u(e);
    int b = mod((int)pow(g,r),p);
    int c = mod(b*a,p);
    int y = dlog(g,p,c);
    return mod(y-r,p);
}

int main()
{
    int g = 1,p,a;
    while(g != 0)
    {
        cout << "Please input g: ";
        cin >> g;
        cout << "Please input p: ";
        cin >> p;
        cout << "Please input a: ";
        cin >> a;

        int x = dlogRH(g,p,a);
        int y = dlog(g,p,a);

        if (x == p) cout << "Result is not exist" << endl;
        else
        {
            cout << "The result is: " << x << endl;
            cout << "The compare result is: " << y << endl;
        }
        
    }
    return 0;
}