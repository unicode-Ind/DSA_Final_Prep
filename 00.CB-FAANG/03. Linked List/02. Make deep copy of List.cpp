// https://leetcode.com/problems/copy-list-with-random-pointer

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

Input Format
single integer n (number of nodes) next n lines containing pairs of integers ( val and index ) NOTE : index can be null also

Constraints
1<=n<=1000

Output Format
Two lines denoting : The old representation of list and the new representation of list as given in sample output . ( Make sure to print output exactly as in the sample output )

Sample Input
5
6 4
4 0 
8 4
9 1
6 2
Sample Output
Old List: (6, 6) (4, 6) (8, 6) (9, 4) (6, 8) 
Copied List: (6, 6) (4, 6) (8, 6) (9, 4) (6, 8) 
Explanation
.
*/

#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node * next = NULL;
    node * random = NULL;
	node(int d) {
		this->data = d;
		this->next = NULL;
        this->random = NULL;
	}
};

node * head = NULL;
node * tail;

unordered_map<int,node*> hm;
void insertAtTail(int d,int i) {
    
    hm[i]= new node(d);
    if (head == NULL) {
		head = tail = hm[i];
	} else {
		tail->next = hm[i];
		tail = tail->next;
	}
}

node* solve(node *head){
    if(head == NULL)
            return NULL;
        
        // create nodes + nxt pointer
        node*l1 = head, *l2=NULL;
        
        for(l1 = head;l1!=NULL; l1 = l1->next->next){
            l2 = new node(l1->data);
            l2->next = l1->next;
            l1->next = l2;
        }
        
        //set random pointer
        for(l1 = head;l1!=NULL; l1 = l1->next->next){
            l2 = l1->next;
            
            if(l1->random != NULL){
                l2->random = l1->random->next;
            }
        }
        
        //separete out
        node * copy = head->next;
         for(l1 = head, l2 = copy;l1!=NULL; l1 = l1->next,l2 = l2->next){
            l1->next = l2->next;
            
             if(l2->next){
                 
                 //vvimp
                 
                 // 1-->1-->NULL
                l2->next = l2->next->next;
             }else{
                 l2->next = NULL;
             }
        }
        
        return copy;
}

int main() {
	head = tail = NULL;
	int n, input;
	cin >> n;

    // take input
    vector<int> random(n);
	for (int i = 0; i < n; i++) {
		cin >> input;
        cin >> random[i];
		insertAtTail(input,i);
	}
    // joining random pointers
    node *temp = head;
    for (int i = 0; i < n; i++) {
		// if(random[i]!=NULL){
        //     temp->random = hm[random[i]]; 
        // } // somehow was giving 0th index = NULL
        temp->random = hm[random[i]]; 
        temp=temp->next;        
	}


	temp = head;
    int out=NULL;
	cout << "Old List: ";
	while (temp) {
		cout <<'(' <<temp->data << ", "<<(temp->random==NULL ? out: temp->random->data) <<") ";
		temp = temp->next;
	}
	cout << endl;

	
	node * deepCopy= temp = solve(head);
	cout << "Copied List: ";
	while (temp) {
		cout <<'(' <<temp->data << ", "<<(temp->random==NULL ? out: temp->random->data) <<") ";
		temp = temp->next;
	}

	return 0;
}

/*
Editorial

Traverse the original list and clone the nodes as you go and place the cloned copy next to its original node. This new linked list is essentially an interweaving of original and cloned nodes.
After the first step, you have already copied the ‘next’ pointers, now we copy the ‘random’ pointers and unweave the lists.
Iterate the list having both the new and old nodes intertwined with each other and use the original nodes’ random pointers to assign references to random pointers for cloned nodes. For eg. If B has a random pointer to A, this means B' has a random pointer to A'.
You have successfully copied the nodes with random pointers, only thing is left is to decouple the original LinkedList from the Cloned one.
Unweaving the linked lists
CODE:

#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
   int val;
   Node* next;
   Node* random;
   Node(int val){
       this->val = val;
       next = NULL;
       random = NULL;
   }
};
Node* createList(int num,unordered_map<Node*,int> &Random,int i,unordered_map<int,Node*> &node_number){
    if(num == 0) {
        node_number[-1] = NULL;
        return NULL;
    }
    int a,b; cin>>a>>b;
    Node* n = new Node(a);
    n->next = createList(num-1,Random,i+1,node_number);
    Random[n] = b;
    node_number[i] = n;
    return n;
}
void printList(Node* head){
    if(head == NULL) return ;
    cout<<"("<<head->val<<", ";
    if(head->random) cout<<head->random->val;
    cout<<") ";
    printList(head->next);
    return ;
}


//Definition of Node 
// class Node{
//   public:
//    int val;
//    Node* next;
//    Node* random;
//    Node(int val){
//        this->val = val;
//        next = NULL;
//        random = NULL;
//    }
// };

Node* copyRandomList(Node* head){
    Node* temp  = head;
    while(temp != NULL){
        Node* n = new Node(temp->val);
        n->next = temp->next;
        temp->next = n;

        temp = temp->next->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->random != NULL){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    temp = head;
    Node* new_head = NULL,*new_tail = NULL;
    while(temp != NULL){
        Node* copy = temp->next;
        if(new_head == NULL){
            new_head = copy;
            new_tail = copy;

            temp->next = copy->next;
            copy->next = NULL;
        }
        else {
            temp->next = copy->next;
            copy->next = NULL;
            new_tail->next = copy;
            new_tail = copy;
        }
        temp = temp->next;
    }
    return new_head;
}




int main() {
    int n; cin>>n;
    unordered_map<int,Node*> node_number;
    unordered_map<Node*,int> Random;
    Node* head = createList(n,Random,0,node_number);
    Node* temp = head;
    while(temp){
        temp->random = node_number[Random[temp]];
        temp = temp->next;
    }
    cout<<"Old List: ";
    printList(head); cout<<endl<<"Copied List: ";
    Node* new_head = copyRandomList(head);
    printList(new_head);
    return 0;
}













// 5
// 6 4
// 4 0 
// 8 4
// 9 1
// 6 2
Make deep copy of List - <i class="fab fa-facebook"></i> <i class="fab fa-apple"></i> <i class="fab fa-amazon"></i>


*/