
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

node *mergeSortedLL(node *a,node *b)
{
        // idea is to merge the linked list into one by altering next pointers of nodes, instead of craeting a new one and copying data to it
        // nodes removed from one and joined to other
        //at end we get two, start pointers , one with soreted mergerd LL and one with empty LL (null)
        // return non empty LL
        if(a==nullptr)
            return b;
        if(b==nullptr)
            return a;

        node *c;
        //comapare a and b for smaller element
        if(a->data < b->data)
           {
                c=a;
                c->next=mergeSortedLL(a->next,b);
           }

       else
           {
                c=b;
                c->next=mergeSortedLL(a,b->next);
           }

       return c;

}

int main()
{
    node *start1=NULL;
    node *start2=NULL;
    //two Linked Lists
    cout<<"Enterd sorted lists:\n";
    cin>>start1>>start2;
    cout<<start1<<start2;

    start1=mergeSortedLL(start1,start2);
    cout<<"\nMerged :"<<start1;


    return 0;
}
