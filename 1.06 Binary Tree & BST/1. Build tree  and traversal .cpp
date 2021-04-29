#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left,*right;
public:
    node(int d=0):left(nullptr),right(nullptr)
    {
        data=d;
        
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

void pre(node *root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void post(node *root)
{
    if(root==nullptr)
        return;

    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

void in(node *root)
{
    if(root==nullptr)
        return;

    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}
int main(){

    node *root=buildTree();

    pre(root);


return 0;
}
