#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(char c) : data(c),lchild(NULL),rchild(NULL) {}
};

int tag = 1;//用来标记二叉树是否唯一
string pre,post;
string in;

TreeNode* TreeBuild(int prel, int prer, int postl, int postr)
{
    if( (prel > prer) || (postr > postr) )
    {
        return NULL;//返回空树
    }

    char c = pre[prel];//当前字符
    TreeNode* root = new TreeNode(c);//创建新节点

    if(prel == prer)//根结点右边没有元素，即没有子树，就不需要判断了
    {
        return root;
    }

    int index = postl;
    while(index < postr && post[index] != pre[prel+1])
    {  //在后序中找前序开始节点的后一个结点的位置
        index ++;
    }
    if(postr-index-1 > 0)//中间有元素，即当前根结点有两个儿子结点
    {
        int sum = index-postl+1;//左子树的大小
        root->lchild = TreeBuild(prel+1,prel+sum,postl,index);
        root->rchild = TreeBuild(prel+1+sum,prer,index+1,postr-1);
    }
    else//没有元素的话，无法判断是左儿子还是右儿子，但肯定是其中之一，假定为右儿子
    {
         tag = 0;//此时树不唯一了
         root->rchild = TreeBuild(prel+1,prer,postl,postr-1);
    }
    return root;
};

void inorder(TreeNode* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->lchild);
    cout << root->data;
    in += root->data;
    inorder(root->rchild);
}

int main()
{
    ifstream fin("4.input.txt");
    ofstream fout("4.output.txt",ios::out|ios::app);
    getline(fin,pre);
    //cout << pre << endl;

    getline(fin,post);
    //cout << post << endl;

    TreeNode *root = TreeBuild(0,pre.size()-1,0,post.size()-1);
    inorder(root);
    fout << in;
    return 0;
}
