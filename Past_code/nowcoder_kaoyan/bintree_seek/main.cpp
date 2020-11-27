#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    char ch;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(char c) : ch(c), lchild(NULL), rchild(NULL) {}
};

TreeNode* build(int& pos,string s)//���ڵݹ��и���posֵ
{
    char c = s[pos++];
    if(c == '#') return NULL;

    TreeNode *root = new TreeNode(c);
    root->lchild = build(pos,s);
    root->rchild = build(pos,s);

    return root;
}

void InOrder(TreeNode* root)
{
    if(root == NULL) return ;

    InOrder(root->lchild);
    cout << root->ch << " ";
    InOrder(root->rchild);

    return ;
}

int main()
{
    string s;
    while(cin >> s)
    {
        int pos = 0;
        TreeNode* root = build(pos,s);//pos���봫��Ϊһ�����������ܴ���0�������ʧ��
        InOrder(root);
        cout << endl;
    }
    return 0;
}
