/*#include <bits/stdc++.h> 
using namespace std; 
struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
void push(Node** headref, int x){
    Node* newNode = new Node(x);
    newNode->next = (*headref);
    (*headref) = newNode;
}
int getMiddle(Node *head) {
    if(head == NULL)    return 0;
       Node *slow, *fast;
       slow = fast = head;
       while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
       }
       return slow->data;
}*/
Node* reverseList(Node* head){
    Node *prev, *curr, *temp;
    prev = temp = NULL, curr = head;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return head = prev;
}

Node* reverseListRecursive(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    
    head->next = NULL;
    return rest;
}

/*
void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}
int main() {
	vector<int> v = {1,2,3,4,5};
	int n = v.size();
	Node* head = NULL;
	for(int i=n-1; i>=0; i--)   push(&head, v[i]);
	head = reverseList(head);
	printList(head);
	return 0;
}*/
