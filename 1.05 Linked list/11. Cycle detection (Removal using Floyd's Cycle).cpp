// Imp interview question
// part 1 :detection only
//detection is simple here and latter modified to make removal easy in part 2
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

void BuildLL(node *&head)  //insertAtTail
{
   int data;
   cin>>data;

   while(data!=-1)
    // -1 used to end the LL, we can also input length and then input  acc
   {
      insertAtTail(head,data);
      cin>>data;
   }
}

istream& operator>>(istream&lin, node*&head)
//void return will work also, but cascading couldnot be done
//istream return allows cascading
// lin is input stream (is more precisely should be used)
{
    BuildLL(head);
    return lin;
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

ostream& operator<<(ostream&lout, node*&head)
{
    show(head);
    return lout;
}

bool detectCycle(node *head)
{
    //Runner technique
    node *slow=head,*fast=head;
    while(fast!=nullptr||fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }

    return false;
}

int main()
{
    node *start1=NULL;
    cin>>start1;
    cout<<start1;



    return 0;
}
