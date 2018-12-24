#include<bits/stdc++.h>
using namespace std;
typedef struct BiNode
{
    int data;                      //结点的值，假设查找集合的元素为整型
    BiNode *lchild, *rchild;         //指向左、右子树的指针
} BiNode;
BiNode * SearchBST(BiNode *root, int k);
BiNode * insertBST(BiNode *tree,int data);
BiNode * createBST(int a[],int n);

int main()
{
    BiNode *root, *t;
    int a[]= {55,42,10,70,63,58,83,67,90,45};
    root=createBST(a,10);
    t=SearchBST(root,58);
    if(t != NULL)
        cout<<"查找成功"<<endl;
    else
        cout<<"查找失败"<<endl;
    return 0;
}
BiNode *insertBST(BiNode *root, int data)
{
    if(root == NULL)
    {
        root = new BiNode;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    if(data <= root->data)
        root->lchild = insertBST(root->lchild, data);
    else
        root->rchild = insertBST(root->rchild, data);
    return root;
}
BiNode *createBST(int a[], int n)
{
    BiNode *T = NULL;
    for (int i=0; i < n; i++)
        T = insertBST(T, a[i]);
    return T;
}
BiNode * SearchBST(BiNode *root, int k)
{
    if (root == NULL)
        return NULL;            //二叉查找树为空，查找失败
    else if (root->data == k)
        return root;           //查找成功
    else if (k < root->data)                   //查找左子树
        return SearchBST(root->lchild, k);
    else                               //查找右子树
        return SearchBST(root->rchild, k);
}
