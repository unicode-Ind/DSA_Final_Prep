#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root) {
    if (root == NULL) {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void printIn(node*root) {
    if (root == NULL) {
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

// Iterative function to perform in-order traversal of the tree
void inorderIterative(node *root)
{
    // create an empty stack
    stack<node*> stack;

    // start from root node (set current node to root node)
    node *curr = root;

    // if current node is null and stack is also empty, we're done
    while (!stack.empty() || curr != nullptr)
    {
        // if current node is not null, push it to the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            // else if current node is null, we pop an element from stack,
            // print it and finally set current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}

void printPost(node*root) {
    if (root == NULL) {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

int height(node*root) {
    if (root == NULL) {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;

}



int main() {
    node* root = buildTree();
    //cout<<count(root)<<endl;
    //printAllLevels(root);
    Pair p = fastDiameter(root);
    cout << p.height << endl;
    cout << p.diameter << endl;

    return 0;
}
