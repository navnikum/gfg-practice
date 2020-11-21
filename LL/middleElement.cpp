#include <bits/stdc++.h> 
using namespace std; 
/*struct Node {
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
} */
int getMiddle(Node *head) {
    if(head == NULL)    return 0;
       Node *slow, *fast;
       slow = fast = head;
       while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
       }
       return slow->data;
}

int main() {
	vector<int> v = {1,2,3,4,5};
	int n = v.size();
	Node* head = NULL;
	for(int i=n-1; i>=0; i--)   push(&head, v[i]);
	cout<<getMiddle(head)<<endl;
	return 0;
}
