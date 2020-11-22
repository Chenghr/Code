#include <iostream>

using namespace std;

const int MAXN = 10000;

int dp[MAXN];
int w[MAXN];//��Ʒ����
int v[MAXN];//��Ʒ��ֵ
int k[MAXN];//��Ʒ����

int weight[MAXN];//��ֺ���Ʒ����
int value[MAXN];//��ֺ���Ʒ��ֵ

int main()
{
    int n,m;//n����Ʒ����������Ϊm

    while(cin >> n >> m)
    {
        int number = 0;//�ֽ����Ʒ����

        for(int i=0; i<n; i++)//�����Ҳ��
        {
            cin >> w[i] >> v[i] >> k[i];

            for(int j=1; j<=k[i]; j<<=1)//���ն����Ʋ�֣�<<1�ȼ��ڳ���2��������λ��������
            {
                weight[number] = j*w[i];
                value[number] = j*v[i];
                number ++;
                k[i] -= j;//����ʣ������
            }
            if(k[i] > 0)//��i����Ʒ��Ȼ��ʣ���δ����
            {
                weight[number] = k[i]*w[i];
                value[number] = k[i]*v[i];
                number ++;
            }
        }

        for(int i=0; i<=m; i++)//dp�����ʼ��
        {
            dp[i] = 0;
        }

        for(int i=0; i<number; i++)//0-1�������
        {
            for(int j=m; j>=weight[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }

        cout << dp[m] << endl;
    }
    return 0;
}
