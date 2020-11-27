#include <iostream>

using namespace std;
const int MAXN = 1000;
int candy[MAXN];//糖果数
int n;//小朋友数
int c;//吹口哨数

bool IsResult()
{
    int temp = candy[0];
    for(int i=1; i<n; i++)
    {
        if(candy[i] != temp) return false;
    }
    return true;
}

void BlowWhistle()//初始为奇数时，分出去较少的那一半，自己留较多的那一半
{
    int share[MAXN];//分享给旁边小朋友的数目
    for(int i=0; i<n; i++)
    {
        share[i] = candy[i]/2;
    }

    c++;//吹哨子
    for(int i=0; i<n-1; i++)
    {
        candy[i] -= share[i];
        candy[i+1] += share[i];
    }
    candy[n-1] -= share[n-1];//单独处理边界问题
    candy[0] += share[n-1];

    for(int i=0; i<n; i++)//奇数补偿
    {
        if(candy[i]%2 == 1) candy[i]++;
    }
    return ;
}

int main()
{
    while(cin >> n)
    {
        if(n == 0) break;

        for(int i=0; i<n; i++)
        {
            cin >> candy[i];
        }
        c = 0;//初始化

        while(!IsResult())
        {
            BlowWhistle();
        }

        cout << c << " " << candy[0] << endl;
    }
    return 0;
}
