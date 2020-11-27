#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int p1;
    int p2;
};

const int N = 27;
Node tree[N];

int preorder(int x,int y,int depth)
{
    if(x == y)
        return depth;
    if(tree[x].p1 != -1)//����������
    {
        int ret = preorder(tree[x].p1,y,depth+1);
        if(ret != -1)//�ҵ���
        {
            return ret;
        }
    }
    if(tree[x].p2 != -1)//����������
    {
        int ret = preorder(tree[x].p2,y,depth+1);
        if(ret != -1)//�ҵ���
        {
            return ret;
        }
    }
    return -1;//���Ҳ���
}

int main()
{
    int n,m;
    while (cin >> n >> m)
    {
        for(int i=0; i<N; i++)//��ʼ����
        {
            tree[i].p1 = -1;
            tree[i].p2 = -1;
        }

        while(n--)//������
        {
            string s;
            cin >> s;

            if(s[1] != '-')
                tree[s[0]-'A'].p1 = s[1]-'A';
            if(s[2] != '-')
                tree[s[0]-'A'].p2 = s[2]-'A';
        }

        while(m--)//������
        {
            string s;
            cin >> s;
            int x = s[0]-'A';
            int y = s[1]-'A';

            int depth1 = preorder(x,y,0);//����xΪ�ӽڵ�
            if(depth1 == 1)
                cout << "child" << endl;
            else if(depth1 >1)
            {
                for(int i=depth1; i> 2; i--)
                {
                    cout << "great-";
                }
                cout << "grandchild" << endl;
            }
            else if(depth1 == -1)//û�ҵ�
            {
                int depth2 = preorder(y,x,0);//��xΪ���Ƚ��
                if(depth2 == 1)
                {
                    cout << "parent" << endl;
                }
                else if(depth2 >1)
                {
                    for(int i=depth2; i> 2; i--)
                    {
                        cout << "great-";
                    }
                    cout << "grandparent" << endl;
                }
                else if(depth2 == -1)//Ҳû�ҵ�
                {
                    cout << "-" << endl;
                }
            }
        }
    }
    return 0;
}
