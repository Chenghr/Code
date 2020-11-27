#include <iostream>

using namespace std;

int main()
{
    int t,m;
    int w[101] = {0};
    int v[101] = {0};
    int dp[1001] = {0};//dp[]�±��ʾ������dp[]�ڴ洢��ǰ�����µ�����ֵ

    while(cin >> t >> m)
    {
        for(int i=0; i<m; i++)
        {
            cin >> w[i] >> v[i];
        }

        for(int i=0; i<t+1; i++)//��ʼ��dp[]����
        {
            dp[i] = {0};
        }

        for(int i=0; i<m; i++)
        {
            for(int j=t; j >= w[i]; j--)//������¹������޸ĵ�dp[j-w[i]]���ʴӺ���ǰ����
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }

        cout << dp[t] << endl;
    }
    return 0;
}
/*
//��������ݱȽϴ��ʱ��ᳬʱ
int t,m;
int wtime[101] = {0};
int value[101] = {0};
int tag[101] = {0};//�����Ʒ�Ƿ�ѡȡ

int maxvalue = 0;
int curvalue = 0;
int curtime = 0;
void search(int n)//���ǵ�n����Ʒ
{
    if(n == m)
    {
        if(maxvalue < curvalue)
        {
            maxvalue = curvalue;
        }
        return ;
    }

    if(t-curtime >= wtime[n])//ѡ��n����Ʒ���뱣֤������
    {
        curtime += wtime[n];
        curvalue += value[n];
        tag[n] = 1;
        search(n+1);

        curtime -= wtime[n];//����
        curvalue -= value[n];
        //����дtag[n] = 0 �͵ò�������ȷ���

    }

    tag[n] = 0;//��ѡȡ��n����Ʒ
    search(n+1);
    return ;
}

int main()
{

    while(cin >> t >> m)
    {
        for(int i=0; i<m; i++)
        {
            cin >> wtime[i] >> value[i];
        }

        maxvalue = 0;//ÿ�����ݶ�Ҫ��ʼ��
        curtime = 0;
        curvalue = 0;
        tag[101] = {0};

        search(0);

        cout << maxvalue << endl;
    }
    return 0;
}
*/
