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

int length(node *head)
{
        int len=0;
        while(head!=nullptr)
        {
            head=head->next;
            len++;
        }
       // cout<<"\n"<<len;
        return len;
}

node * kthNode(node* head, int k)
{
    if(k>length(head))
    {
        cout<<"\nPos over shoots length of LL";
        return nullptr;
    }
    //NOTE: here we are refereing pos : 1,2,3,4... (not index)
    // end condition , when fast =null (not fast->next==null)
    //To visualise draw a LL
    node* slow=head;
    node* fast=head;

    while(k--)
        fast=fast->next;
    while(fast!=nullptr)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
    node *start1=NULL;
    cin>>start1;

    int k;
    cout<<"\nkth pos from end:";
    cin>>k;

    // to do n single pass : Runner technique
    // two pointera : slow = fast = 0 pos (initially)
    // fast : k steps ahead (only once)
    // now move fast and slow both 1 steps ahead simultaneously

    node * ans=kthNode(start1,k);
    if(ans!=nullptr)
        //to check over shoot, in that case ans->data will cause error
    cout<<"\nkth node from end : "<<ans->data;
    return 0;
}
