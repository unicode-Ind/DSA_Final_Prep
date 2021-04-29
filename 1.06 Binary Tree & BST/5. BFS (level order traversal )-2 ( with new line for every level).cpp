#include<iostream>
#include<queue>
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


void pre(node *root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void bfs(node *root)
{
   queue<node*> q;
   //we can't use queue of int type, since by inserting data we wouldn't be able to keep track of it's children
   //we have two options : queue of node* type OR node type
   q.push(root);
   q.push(NULL);

   while(!q.empty())
   {

        node *f=q.front();

        if(f==NULL)
        {
            cout<<endl;
            q.pop();

            if(!q.empty())
                q.push(nullptr);
        }
        else{

        cout<<f->data<<" ";
        q.pop();

        if(f->left)
            q.push(f->left);

        if(f->right)
            q.push(f->right);
        }
   }
}

int main(){

    node *root=buildTree();

    cout<<"Pre-order"<<endl;
    pre(root);
    cout<<endl<<"Level order :\n";
    bfs(root);

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

output:
1
2 3
4 5 7
6
*/
