#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int c) : data(c),lchild(NULL),rchild(NULL) {}//构造函数
};

TreeNode* Insert(TreeNode* root,int x)
{
    if(root == NULL)//插入当前节点
    {
        root = new TreeNode(x);
    }
    else if(x < root->data)//插入左子树
    {
        root->lchild = Insert(root->lchild,x);
    }
    else//插入右子树
    {
        root->rchild = Insert(root->rchild,x);
    }
    return root;
}

//中序遍历
void InOrder(TreeNode* root)
{
    if(root == NULL) return ;

    InOrder(root->lchild);
    cout << root->data << " ";
    InOrder(root->rchild);
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;
        TreeNode* root = NULL;
        int x;

        for(int i=0; i<n; i++)
        {
            cin >> x;
            root = Insert(root,x);
        }

        InOrder(root);
    }
    return 0;
}
