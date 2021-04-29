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

void printKthLevel(node *root,int k)
{
    if(root==nullptr)
        return;
    if(k==1)
    {
        //prints value when k==1
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}

void levelOrder(node *root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        //CAUTION !!!
        //start from i=1, (k=1), at root k=1 initially so it get printed
        // loop till i<=h so that deepest leaf is also printed
        printKthLevel(root,i);
        cout<<endl;
    }
}

void pre(node *root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
int main(){

    node *root=buildTree();

    cout<<"Pre-order"<<endl;
    pre(root);
    cout<<endl<<"Level order :\n";
    //cout<<height(root);
    levelOrder(root);

    //complexity : O(n^2)
    // to find height : O(n)
    // for each level, from root : O(1) + O(2) + O(3) .... or simply 1+2+3+ ....+h = O(h^2)
    //now h can range from log(n) to n (skew- tree)
    //thus, worst case : O(n^2)

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
