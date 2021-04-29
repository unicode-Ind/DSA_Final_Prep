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

//to create LL insertion done at start i.e. head
void ins(node *&head,int data)  //head by reference , insert function at head
{
    node *n=new node(data);
    n->next=head;
    head=n;
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

void delHead(node *&head)
{
    if (head==NULL)
        return;
    node*temp=head;
    head=head->next;
    delete temp;
    return;
}

void delEnd(node *&head)
{
    if (head==NULL)
        return;

    node *prev=nullptr;
    node *temp=head;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=nullptr;
    delete temp;
}

int len(node *head)
// in case pos overshoots length
{
    int len=0;
    while(head!=nullptr)
    {
        head=head->next;
        len++;
    }
    return len;
}

void delpos(node *&head,int pos)
//pos starts from 0 ,assumption
{
        if(head==nullptr)
            return;

        if(pos>len(head))
            {
                delEnd(head);
                return;
                //pos overshoot length : either print unsussessfull(better option) Or delete last
            }
        /*if(pos==0)
            {
                delete(head)
                return;
            }
        */
        node* temp=head,*prev;
        while(pos--)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return;
}

int main()
{
    node *start=NULL;
        ins(start,5);
        ins(start,4);
        ins(start,3);
        ins(start,2);
        ins(start,1);
        ins(start,0);

        show(start);

        delEnd(start);
        show(start);

        delHead(start);
        show(start);

        delpos(start,2);
        show(start);



    return 0;
}
