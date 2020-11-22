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
    if(tree[x].p1 != -1)//左子树存在
    {
        int ret = preorder(tree[x].p1,y,depth+1);
        if(ret != -1)//找到了
        {
            return ret;
        }
    }
    if(tree[x].p2 != -1)//右子树存在
    {
        int ret = preorder(tree[x].p2,y,depth+1);
        if(ret != -1)//找到了
        {
            return ret;
        }
    }
    return -1;//都找不到
}

int main()
{
    int n,m;
    while (cin >> n >> m)
    {
        for(int i=0; i<N; i++)//初始化树
        {
            tree[i].p1 = -1;
            tree[i].p2 = -1;
        }

        while(n--)//构建树
        {
            string s;
            cin >> s;

            if(s[1] != '-')
                tree[s[0]-'A'].p1 = s[1]-'A';
            if(s[2] != '-')
                tree[s[0]-'A'].p2 = s[2]-'A';
        }

        while(m--)//查找树
        {
            string s;
            cin >> s;
            int x = s[0]-'A';
            int y = s[1]-'A';

            int depth1 = preorder(x,y,0);//先视x为子节点
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
            else if(depth1 == -1)//没找到
            {
                int depth2 = preorder(y,x,0);//视x为祖先结点
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
                else if(depth2 == -1)//也没找到
                {
                    cout << "-" << endl;
                }
            }
        }
    }
    return 0;
}
