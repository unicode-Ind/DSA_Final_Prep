/*
We are Given a singly linked list, group all odd nodes together followed by the even nodes. Here we are talking about the node number and not the value in the nodes.
Note: i) You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
ii) The relative order inside both the even and odd groups should remain as it was in the input.
iii) The first node is considered odd, the second node even and so on

Input Format
First line contains the number of nodes n. Next line contains the n node numbers.

Constraints
1<=Length of linked list<=10^4

Output Format
Print the original list and the modified list after Grouping all odd nodes together followed by the even nodes.

Sample Input
10
1 2 3 4 5 6 7 8 9 10
Sample Output
Original List: 1 2 3 4 5 6 7 8 9 10
Modified List: 1 3 5 7 9 2 4 6 8 10
Explanation
None
*/

#include<iostream>
using namespace std;

class node {
public:
	int data;
	node * next = NULL;

	node(int d) {
		this->data = d;
		this->next = NULL;
	}
};

node * head = NULL;
node * tail;

void insertAtTail(int d) {
	if (head == NULL) {
		head = tail = new node(d);
	} else {
		tail->next = new node(d);
		tail = tail->next;
	}

}

node * oddEven() {


	if (head == NULL or head->next == NULL)
		return head;

	node *oddHead = NULL, *oddTail = NULL;
	node *evenHead = NULL, *evenTail = NULL;

	/*
	// initailize even odd head before
		oddHead = oddTail = head;
		evenHead =evenTail = head ->next;

		node * ptr = head->next->next;

		oddTail->next =NULL;
		evenTail->next =NULL;

		while(ptr){
			//odd
			oddTail->next = ptr;
			oddTail = ptr;
			ptr = ptr->next;
			oddTail->next = NULL;

			//even
			if(ptr){

				evenTail->next = ptr;
				evenTail = ptr;
				ptr = ptr->next;
				evenTail->next = NULL;
			}
		}
	*/

	//without intialize even odd head
	node * ptr = head;
	while (ptr) {
		//odd
		if (oddHead == NULL) {
			oddHead = oddTail = ptr;
		} else {
			oddTail->next = ptr;
			oddTail = ptr;
		}
		ptr = ptr->next;
		oddTail->next = NULL;

		//even
		if (ptr) {
			if (evenHead == NULL) {
				evenHead = evenTail = ptr;
			} else {
				evenTail->next = ptr;
				evenTail = ptr;
			}
			ptr = ptr->next;
			evenTail->next = NULL;
		}


	}

	oddTail->next = evenHead;
	evenTail->next = NULL;
	return oddHead;
}

int main() {
	head = tail = NULL;
	int n, input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		insertAtTail(input);
	}

	node* temp = head;
	cout << "Original List: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

	head = oddEven();
	temp = head;
	cout << "Modified List: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	return 0;
}


/*
Editorial
X
Arrange Odd Even linked list Time Complexity : Overall time complexity is O(n).Where n is the number of nodes in the linked list.

Algorithm: Here the task is to group all odd positioned nodes together followed by the even positioned nodes.This can be done by following steps:

Step 1: Inside the function OddEvenList which will return the head of the modified linked list pass head of the given linked list as parameter .

ListNode* OddEvenList (ListNode* head)

Step 2: If the head is equal to NULL return NULL from the function .

Step 3: If head is not NULL then create pointers oddhead, oddtail, evenhead and eventail initially pointing to NULL , temp pointer equal to head and a variable is_odd of boolean type equal to 1 initially.

Step 4: Traverse through the whole linkedlist till temp!=NULL. For the odd position if oddhead is equal to NULL then oddhead= oddtail = temp .Else oddtail->next=temp and oddtail =temp.Then update the temp pointer as temp =temp->next and oddtail->next pointing to NULL.

Step 5: For the Even position if evenhead is equal to NULL then evenhead=eventail=temp. Else eventail->next =temp and eventail=temp.Then update the temp pointer as temp =temp->next and eventail->next pointing to NULL.

Step 6: After one iteration update isodd = !isodd and when temp is equal to NULL update oddtail->next=evenhead.(group odd positioned nodes followed by even positioned nodes). And return oddhead.



Code:

#include <iostream>
using namespace std;
class ListNode{
  public:
   int val;
   ListNode* next;
   ListNode(int val){
       this->val = val;
       next = NULL;
   }
};
ListNode* createList(int num){
    if(num == 0) return NULL;
    int a; cin>>a;
    ListNode* n = new ListNode(a);
    n->next = createList(num-1);
    return n;
}
void printList(ListNode* head){
    if(head == NULL) return ;
    cout<<head->val<<' ';
    printList(head->next);
    return ;
}


// Definition of a node of LinkedList
// class ListNode{
//   public:
//    int val;
//    ListNode* next;
//    ListNode(int val){
//        this->val = val;
//        next = NULL;
//    }
// };

ListNode* oddEvenList(ListNode* head) {
      if(head == NULL) return NULL;
      ListNode* odd_head = NULL;
      ListNode* odd_tail = NULL;
      ListNode* even_head = NULL;
      ListNode* even_tail = NULL;
      ListNode* temp = head;
      bool is_odd = 1;
      while(temp != NULL){
           if(is_odd){
                if(odd_head == NULL){
                    odd_head = odd_tail = temp;
                }
                else {
                    odd_tail->next = temp;
                    odd_tail = temp;
                }
                temp = temp->next;
                odd_tail->next = NULL;
           }
           else {
                    if(even_head == NULL){
                        even_head = even_tail = temp;
                    }
                    else {
                        even_tail->next = temp;
                        even_tail = temp;
                    }
                    temp = temp->next;
                    even_tail->next = NULL;
           }
           is_odd = !is_odd;
      }
      odd_tail->next = even_head;
      return odd_head;
}




int main() {
    int n; cin>>n;
    ListNode* head = createList(n);
    cout<<"Original List: ";
    printList(head); cout<<endl;
    cout<<"Modified List: ";
    printList(oddEvenList(head));
    cout<<endl;
    return 0;
}
*/