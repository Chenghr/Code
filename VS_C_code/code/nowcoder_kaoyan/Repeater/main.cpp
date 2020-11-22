#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

char str[6][6];
char pic[3001][3001];
int n;

int IntPow(int x, int n)
{
    int ans = 1;
    for(int i=1; i<=n; i++)
    {
        ans *= x;
    }
    return ans;
}

void dfs(int x, int y, int m)//(x,y)Ϊ��ͼ�����Ͻǵ���ʼ��
{
    if(m == 1)//�������˻���ͼ�μ���
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                pic[x+i][y+j] = str[i][j];
            }
        }
        return ;
    }

    int ssize = IntPow(n,m-1);

    for(int i=0; i<n; i++)//����ÿһ��λ�ö�Ӧ�����ŵ�λ��
    {
        for(int j=0; j<n; j++)
        {
            if(str[i][j] != ' ')
            {
                dfs(x+i*ssize,y+ssize,m-1);
            }
        }
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;
        cin.get();

        for(int i=0; i<n; i++)
        {
            getline(cin,str[i]);
        }

        int m;
        cin >> m;
        int ssize = (int)pow(n*1.0,m);
        for(int i=0; i<ssize; i++)
        {
            for(int j=0; j<ssize; j++)
            {
                pic[i][j] = ' ';
            }
            pic[i][ssize] = '\n';
        }

        dfs(0,0,m);

        for(int i=0; i<ssize; i++)
        {
            cout << pic[i] << endl;
        }
    }
    return 0;
}
