#include <iostream>
using namespace std;

void ten_two(int n)//十进制转化为二进制
{
    int a[20];//存储转化后的二进制数
    int pos = 0,num = -1;

    while(n)//转化为二进制，注意是逆序存储
    {
        a[pos] = n%2;
        if(a[pos] == 1)
        {
            num++;//判断多少个有效位，便于后面输出加号
        }
        pos++;
        n /= 2;
    }

    for (int i=pos-1; i>=0; i--)
    {
        if(i>1 && a[i]==1)//大于2
        {
            cout << "2(";
            ten_two(i);
            cout << ")";
        }
        else if (i == 1 && a[i] == 1)//等于2
        {
            cout << "2";
        }
        else if (i == 0 && a[i] == 1)//等于1
        {
            cout << "2(0)";
        }
        if(a[i] == 1 && num > 0)//中间位输出加号
        {
            cout << "+";
            num --;
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        ten_two(n);
        cout << endl;
    }
    return 0;
}

