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

int tag = 1;//������Ƕ������Ƿ�Ψһ
string pre,post;
string in;

TreeNode* TreeBuild(int prel, int prer, int postl, int postr)
{
    if( (prel > prer) || (postr > postr) )
    {
        return NULL;//���ؿ���
    }

    char c = pre[prel];//��ǰ�ַ�
    TreeNode* root = new TreeNode(c);//�����½ڵ�

    if(prel == prer)//������ұ�û��Ԫ�أ���û���������Ͳ���Ҫ�ж���
    {
        return root;
    }

    int index = postl;
    while(index < postr && post[index] != pre[prel+1])
    {  //�ں�������ǰ��ʼ�ڵ�ĺ�һ������λ��
        index ++;
    }
    if(postr-index-1 > 0)//�м���Ԫ�أ�����ǰ��������������ӽ��
    {
        int sum = index-postl+1;//�������Ĵ�С
        root->lchild = TreeBuild(prel+1,prel+sum,postl,index);
        root->rchild = TreeBuild(prel+1+sum,prer,index+1,postr-1);
    }
    else//û��Ԫ�صĻ����޷��ж�������ӻ����Ҷ��ӣ����϶�������֮һ���ٶ�Ϊ�Ҷ���
    {
         tag = 0;//��ʱ����Ψһ��
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
