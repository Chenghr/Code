//�൱����ȫ��������ı�ʽ

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int dp[MAXN];//�±��ʾ��ֵ���洢������Ʊ��
int w[MAXN];//��Ʒ����
int v[MAXN];//��Ʒ��ֵ

int main()
{
    int n,m;//m��ʾĿ���ֵ��n��ʾ��Ʊ��Ŀ
    while(cin >> m >> n)
    {
        for(int i=0; i<=m; i++)
        {
            dp[i] = 0x7fffffff-10000;//��ʼ��dp����Ϊһ�����ɴ�״̬
        }

        for(int i=0; i<n; i++)
        {
            cin >> v[i];
            dp[v[i]] = 1;//��ʼ���ɴ�״̬���
        }

        for(int i=0; i<n; i++)
        {
            for(int j=v[i]; j<=m; j++)
            {
                dp[j] = min(dp[j],dp[j-v[i]]+1);//Ҫ����С����Ʊ��
            }
        }

        if(dp[m] == 0x7fffffff-10000) cout << 0 << endl;
        else cout << dp[m] << endl;
    }
    return 0;
}
