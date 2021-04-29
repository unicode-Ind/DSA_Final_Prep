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

bool SearchRec(node *head,int key)
{
    if(head==nullptr)
        return false;
    //Rec Case
    if(head->data==key)
        return true;
    else
        return (SearchRec(head->next,key));
}

bool SearchItr(node *head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
            return true;

        head=head->next;
    }
    return false;

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

        if(SearchRec(start,3))
            cout<<"\nPresent";
        else
            cout<<"\nNot present:";

        if(SearchItr(start,6))
            cout<<"\nPresent";
        else
            cout<<"\nNot present:";

    return 0;
}
