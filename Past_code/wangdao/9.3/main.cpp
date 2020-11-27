#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string result[100];//�洢�˻ʺ�����н�
int q[9] = {0};//�洢��ǰ��
int num = 0;

bool IsOk(int t,int k)//��t��λ�÷���k�Ƿ����
{
    for(int i=1; i<t; i++)
    {
        if(q[i] == k || abs(t-i) == abs(k-q[i]))
        {
            return false;
        }
    }
    return true;
}

void dfs(int t)//ѡȡ��t��λ��
{
    if(t == 9)//�����յ�
    {
        string temp;
        for(int i=1; i<9; i++)
        {
            temp += q[i]+'0';
        }
        result[num++] = temp;
        return ;
    }

    for(int k=1; k<=8; k++)
    {
        if(IsOk(t,k))
        {
            q[t] = k;
            dfs(t+1);

            q[t] = 0;//����
        }
    }
    return ;
}


int main()
{
    int n;
    dfs(1);
    while(cin >> n)
    {
        cout << result[n-1] << endl;
    }
    return 0;
}
