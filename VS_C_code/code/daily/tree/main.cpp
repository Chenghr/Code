#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(char c) : data(c),lchild(NULL),rchild(NULL) {}//构造函数
};

//给定字符串，创建对应树，#表示叶结点;
//int& pos可在函数中修改pos值
TreeNode* Build(int& pos, string str)
{
    char c = str[pos];
    pos ++;//修改pos值

    if(c == '#') return NULL;
    //递归创建子树
    TreeNode* root = new TreeNode(c);//使用构造函数，方便
    root->lchild = Build(pos,str);
    root->rchild = Build(pos,str);
    return root;//返回节点
}

//先序遍历
void PreOrder(TreeNode* root)
{
    if(root == NULL) return ;

    cout << root->data << " ";
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

//中序遍历
void InOrder(TreeNode* root)
{
    if(root == NULL) return ;

    InOrder(root->lchild);
    cout << root->data << " ";
    InOrder(root->rchild);
}

//后序遍历
void PostOrder(TreeNode* root)
{
    if(root == NULL) return ;

    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data << " ";
}

//层次遍历(用到队列)
void LevelOrder(TreeNode* root)
{
    queue<TreeNode*> q;

    if(root == NULL) return;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if(temp->lchild != NULL) q.push(temp->lchild);
        if(temp->rchild != NULL) q.push(temp->rchild);
    }
    return ;
}

int main()
{
    string str;
    while(cin >> str)
    {
        int pos = 0;
        TreeNode* root = Build(pos,str);

        PreOrder(root);
        cout << endl;
        InOrder(root);
        cout << endl;
        PostOrder(root);
        cout << endl;
        LevelOrder(root);
        cout << endl;
    }
    return 0;
}
