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

int count(node *root)
{
    if(root==nullptr)
        return 0;
    return 1+count(root->left)+count(root->right);
}

int sum(node *root)
{
    if(root==nullptr)
        return 0;
    return root->data+sum(root->left)+sum(root->right);
}

int main(){

    node *root=buildTree();

    cout<<"\nSum of node data:";
    cout<<sum(root);

    cout<<"\nTotal no of nodes :"<<count(root);

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
