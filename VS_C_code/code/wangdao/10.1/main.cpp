#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    char c;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    TreeNode(char ch) : c(ch), lchild(NULL), rchild(NULL) {}//同名构造函数
};

TreeNode* Insert(TreeNode* root, char x)//二叉排序树的创建
{
    if(root == NULL)
    {
        root = new TreeNode(x);
    }
    else if(x < root->c)
    {
        root->lchild = Insert(root->lchild,x);
    }
    else
    {
        root->rchild = Insert(root->rchild,x);
    }
    return root;
}

bool IsEqual(TreeNode* t1,TreeNode* t2)//判断两个二叉树是否相同
{
    if(t1 != NULL && t2 != NULL && t1->c == t2->c)
    {
        if(IsEqual(t1->lchild,t2->lchild) && IsEqual(t1->rchild,t2->rchild))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(t1 == NULL && t2 == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;

        vector <TreeNode*> t;
        string s;
        for(int i=0; i<n+1; i++)
        {
            cin >> s;

            TreeNode* root = NULL;
            for(int j=0; j<s.size(); j++)//字符串转化为二叉排序树
            {
                root = Insert(root,s[j]);
            }

            t.push_back(root);
        }

        for(int i=1; i<t.size(); i++)
        {
            if(IsEqual(t[0],t[i]))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
