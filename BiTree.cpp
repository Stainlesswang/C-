/***********************���Ҫ���գ��������ÿ���ݹ���õ��߼��ṹ*********************/
#include<iostream>
using namespace std;

typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    char data;
}BiTreeNode, *BiTree;
//�����*BiTree��˼�Ǹ� struct node*���˸���������BiTree������BiTreeΪָ��ڵ��ָ�롡������������������������  ������������
// ���ҿ�����Ϊָ����������ڵ��ָ�루����ָʾ����������

void createBiTree(BiTree &T)   //�������&��˼�Ǵ��ݵĲ���Ϊָ������ã���������ȼ��� BiTreeNode* &T
{                               // �����ݽ�����ָ��ᷢ���ı䣨���õ����ã���������ȥ��&
    char c;
    cin >> c;
    if('#' == c) {               //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
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

//ǰ���������������ӡ����
void preorder(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
//�����������������ӡ����
void midorder(BiTree T)
{
    if(T)
    {
        midorder(T->lchild);
        cout<<T->data<<" ";
        midorder(T->rchild);
    }
}
//������������������ӡ����
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
//    BiTree T;               //����һ��ָ����������ڵ��ָ��
//    createBiTree(T);
//    cout<<"������������ɣ�"<<endl;
//    cout<<"ǰ�������������"<<endl;
//    preorder(T);
//    cout<<endl;
//    cout<<"���������������"<<endl;
//    midorder(T);
//    cout<<endl;
//    cout<<"���������������"<<endl;
//    postorder(T);
//    return 0;
//}
