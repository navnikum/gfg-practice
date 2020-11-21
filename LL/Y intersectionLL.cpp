// Method 1 O(m+n)
struct Node {
    int data;
    Node* next;/*
    Node(int x){
        data = x;
        next = NULL;
    }*/
};/*
void push(Node** headref, int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = (*headref);
    (*headref) = newNode;
}*/
int LLsize(Node* head){
    Node* curr = head;
    int l=0;
    while(curr != NULL) curr = curr->next, l++;
    return l;
}
int intersectPoint(Node* head1, Node* head2){
    int l1 = LLsize(head1), l2 = LLsize(head2), k;
    Node *curr1, *curr2;
    if(l2 > l1)
        curr1 = head2, curr2 = head1, k = (l2-l1);
    else    
        curr1 = head1, curr2 = head2, k = (l1-l2);
        
    int cnt=0;
    while(cnt<k)    curr1 = curr1->next, cnt++;
    while(curr1 && curr2){
        if(curr1 == curr2)
            return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

// Method 2 : Two Pointer O(m+n) 
int intersectPoint(Node* head1, Node* head2){
    Node *curr1 = head1, *curr2 = head2;
    if(curr1 == NULL || curr2 == NULL)  return -1;
    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;
        if(curr1 == curr2)  return curr1->data;
        if(curr1 == NULL)   curr1 = head2;
        if(curr2 == NULL)   curr2 = head1;
    }
    return -1;
}

/*
void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}*/

int main(){
	
	Node* newNode;

	// Addition of new nodes
	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << "The node of intersection is " << intersectPoint(head1, head2);
}
