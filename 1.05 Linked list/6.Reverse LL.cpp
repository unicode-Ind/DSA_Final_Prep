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

void ReverseItr(node *&head)
{
    node*c=head; //current pointer
    node *pre=NULL; //previous pointer (copm to c)
    node *post;      //next than current (c)

    while(c!=NULL)
    {
        //save the next node
        post=c->next;
        //make current pointer point to prev
        c->next=pre;
        //update prev and current
        pre=c;
        c=post;
    }
    // set new start pointer
    //most crucial step, pre contains here that which was held by current
    //c used to rerminate == null , using head=c will result in empty LL
    head=pre;
}

node* ReverseRec(node *&head)
{
    //base case : smallest LL : 1 node

    //base case
    if(head->next==nullptr|| head==nullptr)
        return head;

    //Rec case
    node *tempHead=ReverseRec(head->next);
    node *current=head;
    current->next->next=current;
    current->next=nullptr;
    return tempHead;
}

int main()
{
    node *start1=NULL;
    //approach 1 : swap(reverse) data : costly, not recomended e.g. when we have say 100 data elements (LL of structure)
    // copying huge amount of data became inefficient , also traversal count is quite hight

    //approach 2: reverse pointer (better, efficent and easy) : iteration ot recursion(rec:interview ques)
    cin>>start1;
    cout<<start1;

    ReverseItr(start1);
    cout<<start1;

   start1=ReverseRec(start1);
    cout<<start1;

    return 0;
}
