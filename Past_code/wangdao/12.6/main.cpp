//�ⷨ2����̬�滮����dp[]�±��ʾ��ֵ���洢���ݱ�ʾ��ǰѡ�õ���Ʊ��

#include <iostream>
using namespace std;

int main()
{
    int target,n;
    const int maxn = 0x7fffffff;//int�ͱ��������ֵ
    int dp[100] = {0};
    int value[20] = {0};

    while(cin >> target >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> value[i];
        }

        for(int i=0; i<=target; i++)//��ʼ��dp����,һ��Ҫ��ʼ�����±�Ϊtarget
        {
            dp[i] = maxn;
        }
        dp[0] = 0;

        for(int i=0; i<n; i++)//�����ж��Ƿ�װ���i����Ʒ
        {
            for(int j=target; j>=value[i]; j--)//���δӺ���ǰ���£�����ʹ�ñ��θ��¹���dp[j-value[i]]
            {
                if(j-value[i] >= 0 && dp[j-value[i]] != maxn)//��֤�±겻Խ��
                {
                    dp[j] = min(dp[j],dp[j-value[i]]+1);
                }
            }
        }

        if(dp[target] == maxn) cout << 0 << endl;
        else cout << dp[target] << endl;
    }

    return 0;
}
/*
//�ⷨ1�����ڵݹ飫���ݵ�˼��

int target,n;
int value[20] = {0};
int tag[20] = {0}; // ����Ƿ�ѡȡ
int flag = 0;//��־�Ƿ��н�
int curvalue = 0;
int minnum;//����ѡȡ��Ʊ��
int num;//��ǰѡȡ��Ʊ��

void choose(int n)//�ж��Ƿ�ѡȡ��ǰ��Ʊ,�Ӻ���ǰѡȡ
{
    if(n == -1)//��������
    {
        if(curvalue == target)
        {
            flag = 1;//�н�
            if(minnum > num) minnum = num;
            return ;
        }
        else return ;
    }

    if(target-curvalue >= value[n])
    {
        curvalue += value[n];
        num ++;
        tag[n] = 1;
        choose(n-1);

        curvalue -= value[n];//����
        num --;
    }
    tag[n] = 0;
    choose(n-1);

    return ;
}

int main()
{
    while (cin >> target >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> value[i];
            tag[i] = 0;//��ʼ���������
        }
        flag = 0;
        curvalue = 0;
        minnum = n;
        num = 0;

        choose(n-1);

        if(flag == 0) cout << 0 << endl;
        else cout << minnum << endl;
    }
    return 0;
}
*/
