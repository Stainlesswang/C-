/***********************这个要掌握，认真理解每个递归调用的逻辑结构*********************/
#include<iostream>
using namespace std;

typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    char data;
}BiTreeNode, *BiTree;
//这里的*BiTree意思是给 struct node*起了个别名，叫BiTree，所以BiTree为指向节点的指针　　　　　　　　　　　　　  　　　　　　
// 并且可以作为指向二叉树根节点的指针（用以指示二叉树）。

void createBiTree(BiTree &T)   //这里加上&意思是传递的参数为指针的引用，括号里面等价于 BiTreeNode* &T
{                               // ，传递进来的指针会发生改变（引用的作用），不可以去掉&
    char c;
    cin >> c;
    if('#' == c) {               //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
        T = NULL;
    }
    else
    {

        T=new BiTreeNode;
        T->data=c;
        createBiTree(T->lchild);
        createBiTree(T->rchild);

    }
}

//前序遍历二叉树并打印出来
void preorder(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
//中序遍历二叉树并打印出来
void midorder(BiTree T)
{
    if(T)
    {
        midorder(T->lchild);
        cout<<T->data<<" ";
        midorder(T->rchild);
    }
}
//后续遍历二叉树并打印出来
void postorder(BiTree T)
{
    if(T)
    {
        postorder(T->lchild);
        postorder(T->rchild);
        cout<<T->data<<" ";
    }
}
//int main()

//{
//    BiTree T;               //声明一个指向二叉树根节点的指针
//    createBiTree(T);
//    cout<<"二叉树创建完成！"<<endl;
//    cout<<"前序遍历二叉树："<<endl;
//    preorder(T);
//    cout<<endl;
//    cout<<"中序遍历二叉树："<<endl;
//    midorder(T);
//    cout<<endl;
//    cout<<"后序遍历二叉树："<<endl;
//    postorder(T);
//    return 0;
//}
