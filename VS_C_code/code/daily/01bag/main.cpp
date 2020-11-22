#include <iostream>

using namespace std;
const int MAXN = 1001;

int dp[MAXN];//�±��ʾ���������ݱ�ʾ��ֵ���ڲ�ͬ��Ŀ�У�ָ�����ݿɸ��ģ�˼·����Ҫ
int w[MAXN];//��Ʒ����
int v[MAXN];//��Ʒ��ֵ

int main()
{
    int n,m;//n����Ʒ������Ϊm
    while(cin >> n >> m)
    {
        for(int i=0; i<n; i++)//����
        {
            cin >> w[i] >> v[i];
        }

        for(int i=0; i<=m; i++)//��ʼ��dp����,ע��i<=m,Ҫ���µ�m
        {
            dp[i] = 0;
        }

        for(int i=0; i<n; i++)//�����жϵ�i����Ʒ
        {
            for(int j=m; j >= w[i]; j--)//������£� j>=w[i]��Ϊ�˱�֤ dp[j-w[i]]�±겻Ϊ��
            {
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);//dp[j]��ʾ��ѡȡ��i����Ʒ��dp[j-w[i]]+v[i]��ʾѡȡ��i����Ʒ
            }
        }

        cout << dp[m] << endl;
    }
    return 0;
}
