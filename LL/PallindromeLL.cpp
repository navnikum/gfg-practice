// Using Stack O(n) O(n)
bool isPalindrome(Node* head){
	Node* curr= head; 
	stack <int> s;
	while(curr)	s.push(curr->data), curr = curr->next;
	while(head != NULL ){
		if(head -> data != s.top())     return 0;
        s.pop();
		head=head->next;
	}
	return 1;
}

// Recursion
bool util(Node** l, Node* r){
    if(r==NULL) return true;
    bool temp = util(l, r->next);
    if(temp == false)   return temp;
    bool res = r->data == (*l)->data;
    *l = (*l)->next;
    return res;
}
bool isPalindrome(Node *head){
    return util(&head, head);
}

// Pallindrome LL find mid and reverse
// O(n) 
void reverse(Node** head_ref){ 
	Node* prev = NULL, current = *head_ref, next; 
	while (current) { 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
}
bool compareLists(struct Node* head1, struct Node* head2){ 
  	if (!head1 && !head2)	return 1; 
	Node* temp1 = head1, temp2 = head2; 
 
	while (temp1 && temp2) { 
		if (temp1->data != temp2->data) 
        	return 0;  
		temp1 = temp1->next; 
		temp2 = temp2->next; 
	} 
	return 1; 
}
bool isPalindrome(Node *head) {
    bool res = true;
    Node *slow, *fast, *prev_slow = NULL, *midNode = NULL, *secondHalf;
    slow = fast = head;
    if(head && head->next){
        while(fast && fast->next){
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }
        if(fast != NULL){ // odd list store middle node somewhere
            midNode = slow;
            slow = slow->next;
        }
        secondHalf = slow;
        prev_slow->next = NULL;
        reverse(&secondHalf);
        res = compareLists(head, secondHalf);
        reverse(&secondHalf);
        // odd list
        if(midNode != NULL){
            prev_slow->next = midNode;
            midNode->next = secondHalf;
        }
        else    // even list
            prev_slow->next = secondHalf;
    }
    return res;
}
