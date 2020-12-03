ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A == NULL) return NULL;
    ListNode *head,*curr,*next,*prev;
    curr = A; prev = NULL;
    for(int i = 0; i<B;i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(next)  A->next = reverseList(next,B);
    return prev;
}


// alternate k node
ListNode* Solution::solve(ListNode* A, int B) {
    if(A == NULL) return NULL;
    ListNode *head,*curr,*next,*prev;
    curr = A; prev = NULL;
    for(int i = 0; i<B;i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    A->next = curr;
    if(!curr) return prev;
    // go fwd
    for(int i = 0; i<B-1;i++)
        curr = curr->next;
    
    curr->next = solve(curr->next,B);
    return prev;
}
