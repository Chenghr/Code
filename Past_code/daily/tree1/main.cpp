#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(char c) : data(c),lchild(NULL),rchild(NULL) {}//���캯��
};

TreeNode* Build(string pre,string in)//������������������
{
    if(pre.size() == 0) return NULL;

    char c = pre[0];
    TreeNode* root = new TreeNode(c);

    int pos = in.find(c);//����in�ַ�����c�״γ��ֵ��±�
    root->lchild = Build(pre.substr(1,pos), in.substr(0,pos));//�ݹ鴴��������
    root->rchild = Build(pre.substr(pos+1),in.substr(pos+1));//�ݹ鴴��������
    return root;
}

//�������
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
