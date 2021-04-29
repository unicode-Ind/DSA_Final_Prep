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

void operator>>(istream&lin, node*&head)
//void return will work also, but cascading couldnot be done
//istream return allows cascading
// lin is input stream (is more precisely should be used)
{
    BuildLL(head);
    //return lin;
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

void operator<<(ostream&lout, node*&head)
{
    show(head);
   // return lout;
}

node* midPointM1(node *head)
{
   if(head==nullptr|| head->next==nullptr)
        return head;

    node* slow=head;
    node* fast=head->next; //fast at 1 to get m1 (if length even)

    while(fast!=nullptr && fast->next!=nullptr)
        //CAUTION !!!
        //use && not OR (||) as it will not stop in case of OR
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

/*
node* midPointM2(node *head)
{
   if(head==nullptr|| head->next==nullptr)
        return head;

    node* slow=head;
    node* fast=head; //fast at 0 to get m2 (if length even)

    while(fast!=nullptr && fast->next!=nullptr)
        //CAUTION !!!
        //use && not OR (||) as it will not stop in case of OR
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
*/

int main()
{
    node *start1=NULL;
    cin>>start1;

    //here we use two pointers: one fast and other slow, fast take two jumps while slow one takes one jump at a time
    // when fast reaches end , slow one will be at mid
    // fast can either end at last node or to next of last node (address) i.e. need to consider both cases

    //if no of nodes are even then two mid points ,say m1 and m2 (resp in order)
    // to find m1 intialize slow @ 0 and fast @ 1 pos
    // to find m2 intialize slow = fast =0 pos
    node* mid1=midPointM1(start1);
    cout<<"Mid node ,M1 :"<<mid1->data;


    return 0;
}
