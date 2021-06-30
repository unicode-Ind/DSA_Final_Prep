/*
Given a linked list, remove the k-th node from the end of list.

Input Format
First line contains a single integer N denoting the size of the linked list.
Second line contains a single integer K denoting remove k-th node from the end of list
Third line contains N space separated integers denoting the elements of the linked list.

Constraints
Note :Given k will always be valid.

Output Format
Display updated linked list

Sample Input
15
3
1 2 2 1 2 3 4 5 6 1 2 3 4 5 7
Sample Output
1 2 2 1 2 3 4 5 6 1 2 3 5 7
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

node * deleteKthFromEnd(int k) {
	if (!head or k < 1)
		return head;

	node *fast = head;
	node *slow = head, *followSlow = NULL;

	int i;
	for (i = 0; i < k and fast; i++) {
		fast = fast -> next;
	}

	//lenght <k =>no deletion
	if (i < k)
		return head;

	// to delete head => prev cant be found
	if (!fast)
		return head = head->next;

	//normal case
	// 1 2 3 4 (k=2)
	// s   f
	while (fast) {
		fast = fast->next;
		followSlow = slow;
		slow = slow ->next;
	}

	// 1 2 3 4 (k=2)
	// 	 f s   f
	followSlow->next = slow->next;
	delete slow;
	return head;
}

int main() {
	head = tail = NULL;
	int n, k, input;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> input;
		insertAtTail(input);
	}

	node* temp = deleteKthFromEnd(k);
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	return 0;
}

/*
Editorial
X
Kth From the End
Time Complexity O(n), where n is the linkedlist size.
Given a linked list, remove the n-th node from the end of list and return its head.
Algorithm:
Steps:
1.Take two pointers, first and second
Initially first and second will be point head.
Now continue raising the second pointer until the second pointer points to the Nth node from the beginning
first will point to the head of the linked list and second will point to the Nth node from the beginning.
2.Now keep increment both the pointers by one at the same time until the second is pointing to the last node of the linked list.
3.After the operations from the previous step, the first pointer should be pointing to the Nth node from the end by now. So, delete the node the first pointer is pointing to.

Solution Link :https://ide.geeksforgeeks.org/GT4qUMv9rL


import java.util.*;
public class Main {

    static class ListNode
    {
        int data;
        ListNode next;
    }

    public static ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode fast = head, slow = head;
        for(int i=0;i<n;i++)
            fast = fast.next;

        if(fast == null) return head.next;

        while(fast != null && fast.next != null)
        {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return head;
    }

    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
          int k = scn.nextInt();
        ListNode head = new ListNode();
        head.data = scn.nextInt();
        ListNode t = head;
        for(int i=1;i<n;i++) {
            t.next = new ListNode();
            t.next.data = scn.nextInt();
            t = t.next;
        }
        t.next = null;


        ListNode h = removeNthFromEnd(head,k);
        while(h != null)
        {
            System.out.print(h.data + " ");
            h = h.next;
        }
    }
}
*/