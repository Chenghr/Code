#include <iostream>

using namespace std;

int FastE(int a, int b)
{
    int answer = 1;
    while(b != 0)//���Ͻ�bת��Ϊ��������
    {
        if(b%2 == 1)//����ǰλΪ1���۳�a��2^k����
        {
            answer *= a;
        }
        b /= 2;
        a *= a; //a����ƽ��
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
