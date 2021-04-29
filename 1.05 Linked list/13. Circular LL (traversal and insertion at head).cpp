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

int main()
{
    node *start=nullptr,*start2=nullptr;
    pushAtHead(start2,1);
    show(start2);
    pushAtHead(start,2);
    pushAtHead(start,3);
    pushAtHead(start,4);
    pushAtHead(start,5);
    pushAtHead(start,6);

    show(start);
    return 0;
}
