Node* reverseSubList(Node* head, int k){
    Node *prev, *curr, *next;
    prev=next = NULL, curr=head;
    int cnt=0;
    while(curr && cnt < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if(next != NULL)
        head->next = reverseSubList(next, k);
        
    return prev;
}
