#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(char c) : data(c),lchild(NULL),rchild(NULL) {}//构造函数
};

TreeNode* Build(string pre,string in)//由先序和中序构造二叉树
{
    if(pre.size() == 0) return NULL;

    char c = pre[0];
    TreeNode* root = new TreeNode(c);

    int pos = in.find(c);//返回in字符串中c首次出现的下标
    root->lchild = Build(pre.substr(1,pos), in.substr(0,pos));//递归创建左子树
    root->rchild = Build(pre.substr(pos+1),in.substr(pos+1));//递归创建右子树
    return root;
}

//后序遍历
void PostOrder(TreeNode* root)
{
    if(root == NULL) return ;

    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data << " ";
}

int main()
{
    string pre,in;
    while(cin >> pre >> in)
    {
        TreeNode* root = Build(pre,in);
        PostOrder(root);
        cout << endl;
    }
    return 0;
}
