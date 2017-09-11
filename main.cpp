
/***********************二叉树遍历*********************/
#include <iostream>

using namespace std;

template<class Type>
class BSTree;

template<class Type>
class BinaryNode{
    friend class BSTree<Type>;
public:
    BinaryNode(): left(NULL),right(NULL){}
    BinaryNode(const Type& value): data(value),left(NULL),right(NULL){}
private:
    Type data;
    BinaryNode *left;
    BinaryNode *right;

};

template<class Type>
class BSTree{
    BinaryNode<Type> *root;
public:
    BSTree(): root(NULL){}
    BinaryNode<Type>* GetRoot() const{return root;}
    //用来加入一个新的值,并返回加入的值
    Type AddValue(const Type& value);
    //以startNode为根节点打印其子节点数据
    void printData_NLR(const BinaryNode<Type> *startNode); //前序遍历
    void printData_LNR(const BinaryNode<Type> *startNode); //中序遍历
    void printData_LRN(const BinaryNode<Type> *startNode); //后续遍历
    void Cout(){

    }
};

template<class Type>
Type BSTree<Type>::AddValue(const Type& value){
    if(root == NULL){
        root = new BinaryNode<Type>(value);
    }else{
        BinaryNode<Type> *node = root;
        while(1){
            if(value > node->data){
                if(node->right == NULL){            //此时node已经定位在空的节点处了
                    node->right = new BinaryNode<Type>(value);
                    break;
                }else{
                    node = node->right;
                }
            }else{
                if(node->left == NULL){
                    node->left = new BinaryNode<Type>(value);
                    break;
                }else{
                    node = node->left;
                }
            }

        }
    }
    return value;
}


//前序遍历
template<class Type>
void BSTree<Type>::printData_NLR(const BinaryNode<Type> *startNode){
    if(startNode == NULL){
        return;
    }else{
        cout << startNode->data << " ";
        printData_NLR(startNode->left);
        printData_NLR(startNode->right);
    }
}


//中序遍历
template<class Type>
void BSTree<Type>::printData_LNR(const BinaryNode<Type> *startNode){
    if(startNode == NULL){
        return;
    }else{
        printData_LNR(startNode->left);
        cout << startNode->data << " ";
        printData_LNR(startNode->right);
    }
}


//后序遍历
template<class Type>
void BSTree<Type>::printData_LRN(const BinaryNode<Type> *startNode){
    if(startNode == NULL){
        return;
    }else{
        printData_LRN(startNode->left);
        printData_LRN(startNode->right);
        cout << startNode->data << " ";
    }
}


int main(){
    BSTree<int> tree;
    /********************填充数据*****************************/
    tree.AddValue(7);
    tree.AddValue(4);
    tree.AddValue(10);
    tree.AddValue(1);
    tree.AddValue(5);
    tree.AddValue(-1);
    tree.AddValue(2);
    tree.AddValue(9);
    tree.AddValue(13);
    tree.AddValue(12);
    tree.AddValue(11);
    tree.AddValue(14);
    /*********************************************************/

    cout << "前序遍历" << endl;
    tree.printData_NLR(tree.GetRoot());
    cout << "\n\n中序遍历" << endl;
    tree.printData_LNR(tree.GetRoot());
    cout << "\n\n后序遍历" << endl;
    tree.printData_LRN(tree.GetRoot());

    return 0;
}