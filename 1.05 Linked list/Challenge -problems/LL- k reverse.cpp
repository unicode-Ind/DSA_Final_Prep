#include<iostream>
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

void buildLL(node *&head,int n)  //insertAtTail
{
   int data;
   //cin>>data;

   while(n--)
    // -1 used to end the LL, we can also input length and then input  acc
   {
       cin>>data;
      insertAtTail(head,data);

   }
   //cout<<"create";
}

void show(node *&head)
{
    node*temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    //cout<<"showed";
    delete temp;
}
node* reverse(node *&head)
{
    //base case : smallest LL : 1 node

    //base case
    if(head->next==nullptr|| head==nullptr)
        return head;

    //Rec case
    node *tempHead=reverse(head->next);
    node *current=head;
    current->next->next=current;
    current->next=nullptr;
    return tempHead;
}

void merge(node *&head,node *&b)
{
    if(b==nullptr)
    return;
    node *temp=head;
    while(temp->next!=nullptr)
        temp=temp->next;

    temp->next=b;
    delete temp;
}

void ans(node *&head, int size)
{
    cout<<"ans";
    if(head==nullptr)
    return;
    node *b=head,*a=NULL;
    int k=size;

    while(k--){
        a=b;
        b=b->next;
    }
    a->next=NULL;
    head=
    reverse(head);
    ans(b,size);
    merge(head,b);
    delete b;
    delete a;
}

int main() {
	node *head=NULL;

	int n,k;
	cin>>n>>k;
	buildLL(head,n);
	show(head);

    ans(head,k);
    show(head);
	return 0;
}
