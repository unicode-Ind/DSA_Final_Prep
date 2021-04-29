#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left,*right;
public:
    node(int d=0)
    {
        data=d;
        left=right=nullptr;
    }
};

node *buildTree()
{
    //input in pre-order
    int d;
    cin>>d;
    if(d==-1)
        return nullptr;

    node *n=new node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}

int height(node *root)
{
    if(root==nullptr)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}

int diameter(node *root){
    if(root==nullptr)
        return 0;
    int op1=height(root->left)+height(root->right);
    //case 1: diameter passed through root
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));
}
int main(){

    node *root=buildTree();
    cout<<"\nDiameter of tree :"<<diameter(root);

return 0;
}
/*
input :
1
2
4
-1
-1
5
6
-1
-1
-1
3
-1
7
-1
-1
*/
