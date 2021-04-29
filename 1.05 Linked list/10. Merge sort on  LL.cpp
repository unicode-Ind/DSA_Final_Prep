
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

node *mergeSort(node *head)
{
    //base case
    if(head==nullptr|| head->next==nullptr)
        return head;

    //Rec Case
    //1. mid point
    node *mid=midPointM1(head);

    node *a=head;
    node *b=mid->next;
    mid->next=nullptr;

    //2. Recursively Sort
    a=mergeSort(a);
    b=mergeSort(b);

    //3. merge a and b
    node *c=mergeSortedLL(a,b);
    return c;
}

int main()
{
    node *start1=NULL;

    cin>>start1;
    cout<<start1;

    //step 1 : divide- break mid
    //sort the smaller LL (recursion)
    //merge sorted parts

    start1=mergeSort(start1);
    cout<<"\nMerge sorted :"<<start1;

    //complexity
    //step:                            array                 LL
    // finding mid                      O(1) =k              O(n)         caling midPointM1
    //diving into two parts             2 T(n/2)             2 T(n/2)     node *a=head;
       //                                                                 node *b=mid->next;
      //                                                                  mid->next=nullptr;
    // calling merge                    O(n)                  O(n)

    //OVERALL  T(n)=                    K+ 2 T(n/2)+k.n      kn+ 2 T(n/2)+ k.n
    //effectively both are same => mergeSort takes nlog2(n) for Linked List too

    return 0;
}
