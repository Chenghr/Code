//����ΪN����¥������
#include <iostream>
using namespace std;

int result = 0;
void getresult(int n)//�ݹ鷽��
{
    if(n == 0)
    {
        result ++;
        return ;
    }
    if(n >= 2)
    {
        getresult(n-1);//��һ��
        getresult(n-2);//������
    }
    else//ֻʣһ���ɿ�����
    {
        getresult(n-1);
    }
    return ;
}

int main()
{
    int n;
    int dp[20] = {0};//��ʼ����������
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<20; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];//��n��Ҫô��n-2�׿�����������Ҫô��n-1�׿�һ������
    }

    while (cin >> n)
    {
        cout << dp[n] << endl;

        /* �ݹ����
        result = 0;
        getresult(n);
        cout << result << endl;
        */
    }
    return 0;
}
