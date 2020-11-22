#include <iostream>
using namespace std;

int main()
{
    int dp[1000001] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=1000000; i++)
    {
        if(i%2 == 0)
        {
            dp[i] = (dp[i-1]+dp[i/2]) % 1000000000;
        }
        else
        {
            dp[i] = dp[i-1] % 1000000000;
        }
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}
/*
����Խ���ˣ�TMD����֪��Ϊɶ������

//��Ϊ��ȫ�������⣬ÿ����Ʒ�����ظ�ѡȡ��
//��Ʒ�Ļ�������Ϊ1,2,4,8... �����nΪ1000000����20����Ʒ������
//dp[i][j]��ʾǰi����Ʒǡװ��������СΪj�ı����ķ���������
//dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i]],�ɽ�һ����Ϊdp[j]
//����n �����Ӧ��dp[n]����

#include <iostream>
using namespace std;

int main()
{
    long long dp[1000001];
    long long value[21];
    value[0] = 1;
    for(int i=1; i<=20; i++)//��ʼ��
    {
        value[i] = value[i-1]*2;
    }
    for(int i=0; i<=1000000; i++)
    {
        dp[i] = 1;
    }

    for(int i=1; i<=20; i++)
    {
        for( long long j=value[i]; j<=1000000; j++)
        {
            dp[j] = dp[j]+dp[j-value[i]];
            if(dp[j] >= 1000000000) dp[i] = dp[i]%1000000000;
        }
    }

    int n;
    while(cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}
*/
