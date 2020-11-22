#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int c) : data(c),lchild(NULL),rchild(NULL) {}//���캯��
};

TreeNode* Insert(TreeNode* root,int x)
{
    if(root == NULL)//���뵱ǰ�ڵ�
    {
        root = new TreeNode(x);
    }
    else if(x < root->data)//����������
    {
        root->lchild = Insert(root->lchild,x);
    }
    else//����������
    {
        root->rchild = Insert(root->rchild,x);
    }
    return root;
}

//�������
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
