/*
Given a linked list, swap every two adjacent nodes and print linked list
note: You may not modify the values in the list's nodes, only nodes itself may be changed.

Input Format
First line contains a single integer N denoting the size of the linked list. Second line contains N space separated integers denoting the elements of the linked list.

Constraints
None

Output Format
First-line display an original linked list Second line display the linked list after swapping pairwise nodes.

Sample Input
5
1 2 3 4 5
Sample Output
1 -> 2 -> 3 -> 4 -> 5 ->
2 -> 1 -> 4 -> 3 -> 5 ->
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


node* insertAtTail(node *head, node *tail, int d) {
	if (head == NULL) {
		head = tail = new node(d);
	} else {
		tail->next = new node(d);
		tail = tail->next;
	}
	return head;
}

node * swapPair(node * head) {
	if (!head or !head->next)
		return head;

	node * first = head;
	node * second = head->next;
	node * third = second->next;

	second->next = first;
	first->next = swapPair(third);

	return second;

}

int main() {
	node * head;
	node * tail;
	head = tail = NULL;

	int n, input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		//head=insertAtTail(head,tail,input);
		//cout<<input;
		if (head == NULL) {
			head = tail = new node(input);
		} else {
			tail->next = new node(input);
			tail = tail->next;
		}
	}

	node* temp = head;
	//cout << "Original List: ";
	while (temp) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << endl;

	head = swapPair(head);
	temp = head;
	//cout << "Modified List: ";
	while (temp) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	return 0;
}

/*
Question: Swap Nodes in Pair
Time Complexity O(n), where n is the linkedlist size.
Algorithm: The above problem of swapping nodes in a pair can be solved using following algorithm whose steps are as below:
Step 1: Take linkedlist as input and pass it to a function namely ‘Swap_nodes’.

Step 2: Inside the function using recursive method swap two nodes pairwise.

i) Evertime we compare two nodes and keep on swapping them with the help of recursive function Swap_nodes() till either node is equal to null or next of node equal to null (node == null || node.next == null) which is the base case of the function.This base case will help us to avoid Null pointer Exception.
ii) The base case will return the node.

return node;

Step 3: On reaching the last two nodes of the linkedlist we will interchange the link that is pointing from secondlast element to last element, to point it in reverse direction.

Step 4: Print the linked list which is the desired output.

Pseudocode:
Swapnodes(Node node)
if (node == null || node.next == null) // Base Case
return node;
ListNode swap = Swapnodes(node.next.next);
ListNode another = node.next;
another.next = node;
node.next = swap;
return another;
Solution link: https://ide.codingblocks.com/s/201077

public class Main{
public static void main(String[] args) {
    ListNode head = make();
    display(head);
    head  = Swap_nodes(head);
    display(head);
}

public static ListNode Swap_nodes(ListNode node ) {
    if(node == null || node.next == null)  // Base Case
        return node ;

    ListNode swap = Swap_nodes(node.next.next);

    ListNode another = node.next;
    another.next = node;
    node.next = swap ;

    return another;

}

  public  static class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
  }
 public static ListNode make() {
     int n = 5 ;
     ListNode head = new ListNode(1);
     ListNode prev = head;
     for(int i =2 ; i<=5 ;i++) {
         ListNode nn = new ListNode(i);
         prev.next = nn;
         prev = nn;
     }
     return head;
 }
 public static void display(ListNode root ) {
     if(root == null) {
    System.out.println();
         return;}
     System.out.print(root.val+" -> ");
     display(root.next);
 }

}
*/