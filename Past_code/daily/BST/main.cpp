#include <iostream>

using namespace std;

const int MAXN = 10000;

struct TreeNode
{
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(int v) : val(v),lchild(NULL),rchild(NULL) {}
};

int a[MAXN] = {0};
int n;
bool tag = true;

TreeNode* create(int l,int r)//±éÀúÇÒÅÐ¶ÏÊÇ·ñÂú×ãBST
{
    if(!tag || l > r) return NULL;

    TreeNode* root = new TreeNode(a[l]);
    if(l == r)
    {
        return root;
    }

    int mid;
    for(mid = l+1; mid <= r; mid++)
    {
        if(a[mid] > a[l]) break;
    }

    root->lchild = create(l+1,mid-1);

    int j;
    for(j=mid; j<=r; j++)
    {
        if(a[j] < a[l])
        {
            tag = false;
            return NULL;
        }
    }

    root->rchild = create(mid,r);

    return root;
}

void post(TreeNode* root)
{
    if(root == NULL) return ;

    post(root->lchild);
    post(root->rchild);
    cout << root->val << " ";
}

int main()
{
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        TreeNode* root = create(0,n-1);

        if(tag == false) cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            post(root);
        }
    }
    return 0;
}
