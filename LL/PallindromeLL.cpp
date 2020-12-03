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

int Solution::lPalin(ListNode* A) {
    ListNode *slow = A, *fast = A;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //  1 2 3 5 4 6 7 // odd : slow = mid_elem ; fast = end
    //  1 2 3 5 4 6   // even: slow = mid+1 ; fast = null 
    slow = reverse(slow);
    fast = A;
    while(fast && slow){
        if(fast->val != slow->val)
            return 0;
        fast = fast->next;
        slow = slow->next;
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
