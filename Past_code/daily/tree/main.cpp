#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(char c) : data(c),lchild(NULL),rchild(NULL) {}//���캯��
};

//�����ַ�����������Ӧ����#��ʾҶ���;
//int& pos���ں������޸�posֵ
TreeNode* Build(int& pos, string str)
{
    char c = str[pos];
    pos ++;//�޸�posֵ

    if(c == '#') return NULL;
    //�ݹ鴴������
    TreeNode* root = new TreeNode(c);//ʹ�ù��캯��������
    root->lchild = Build(pos,str);
    root->rchild = Build(pos,str);
    return root;//���ؽڵ�
}

//�������
void PreOrder(TreeNode* root)
{
    if(root == NULL) return ;

    cout << root->data << " ";
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

//�������
void InOrder(TreeNode* root)
{
    if(root == NULL) return ;

    InOrder(root->lchild);
    cout << root->data << " ";
    InOrder(root->rchild);
}

//�������
void PostOrder(TreeNode* root)
{
    if(root == NULL) return ;

    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data << " ";
}

//��α���(�õ�����)
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
