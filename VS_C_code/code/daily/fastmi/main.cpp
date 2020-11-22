#include <iostream>

using namespace std;

int FastE(int a, int b)
{
    int answer = 1;
    while(b != 0)//不断将b转化为二进制数
    {
        if(b%2 == 1)//若当前位为1，累乘a的2^k次幂
        {
            answer *= a;
        }
        b /= 2;
        a *= a; //a不断平方
    }
    return answer;
}

int main()
{
    int a,b;
    while(cin >> a >> b)
    {
        cout << FastE(a,b) << endl;
    }
    return 0;
}
