#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data=d;
        next=NULL;
    }
};

void pushAtHead(node *&head, int data){
//insertion at head
    node *ptr=new node(data);
    //new node
    node *temp=head;
    //used to traverse , to act as tail pointer
    ptr->next=head;

    if(head!=nullptr){
        while(temp->next!=head)
            temp=temp->next;

        temp->next=ptr;
    }
    else{
        ptr->next=ptr;
    }

    head=ptr;
}

void show(node *head)
{
    if(head==nullptr)
        return;
    node *temp=head;
    //think of case when there is only one node
    while(temp->next!=head)
    {
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<temp->data<<endl;
    //one node case done by this
    //in while loop last node will not be printed, by doing this it is printed now
}

node* getNode(node *head,int data)
{
    if(head==nullptr)
        return nullptr;
    node *temp=head;
    while(temp->next!=head)
    {
        if(temp->data==data)
            return temp;

        temp=temp->next;
    }
    if(temp->data==data)
            return temp;
            //check for last node
    else
    return NULL;
}

void deleteNode(node *&head,int data){
// why head as reference i.e. we want to update head ?
//head will also be altered when deleton is done at head
    node *del=getNode(head,data);
    if(del==nullptr)
    {
        cout<<"\nNot present \n";
        return;
    }

    if(head ==del)
    {
        //spl case handling
        head=del->next;
    }

    else{
        node *temp=head;
        while(temp->next!=del)
            temp=temp->next;

        temp->next=del->next;
    }
    delete del;
}

int main()
{
    node *start=nullptr;
    pushAtHead(start,1);
    pushAtHead(start,2);
    pushAtHead(start,3);
    pushAtHead(start,4);
    pushAtHead(start,5);
    pushAtHead(start,6);
    show(start);

    deleteNode(start,1);
    show(start);

    deleteNode(start,6);
    show(start);

    deleteNode(start,4);
    show(start);


    return 0;
}
