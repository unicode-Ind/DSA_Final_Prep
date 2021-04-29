#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};
/*
class LinkedList{
node *head,*tail;
public:
    LinkedList()
    {
        head=tail=NULL;
    }
};
*/

void insertAtHead(node *&head,int data)  //head by reference
{
    node *n=new node(data);
    n->next=head;
    head=n;
}

int len(node *head)
{
    int len=0;
    while(head!=nullptr)
    {
        head=head->next;
        len++;
    }
    return len;
}

void insertAtTail(node *&head,int data)
{
    if(head==nullptr)
        {
            head=new node(data);
            return;
        }
    node *tail=head;
    while(tail->next!=nullptr)
        tail=tail->next;
    tail->next=new node(data);

}

void insertAtMid(node *&head,int data,int pos)  //p pos means p-1 jumps
{
   if(head==nullptr || pos==0)          //pos assumed to start from 0
        insertAtHead(head,data);

        //if pos > length of LL
   else if(pos>len(head))
        insertAtTail(head,data);

    else                                   //insert at mid (pos)
        {
            node *n,*temp=head;
            /*alternatively

            int jump=1;
            node *temp=head;
            while(jump<=p-1)
            {
             temp=temp->next;
             jump++;
            }
            */
            while(--pos)
            temp=temp->next;

            n=new node(data);
            n->next=temp->next;
            temp->next=n;
        }

}

void show(node *head)  //head by value
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node *start=NULL;
        insertAtHead(start,5); //passing by reference changes head
        insertAtHead(start,4);
        insertAtHead(start,3);

        show(start);
        show(start); //passing by value doesnot change head

        insertAtMid(start,0,1);
        show(start);

        insertAtTail(start,9);
        show(start);

    return 0;
}
