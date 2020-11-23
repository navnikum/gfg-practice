Node* pairWiseSwap(Node* head){
    if (head == NULL || head->next == NULL) 
        return head; 
    // swap first two
    Node *curr, *prev;
    prev = head; 
    curr = head->next->next;
    // reverse link
    head->next->next = head;
    // fix head
    Node* newhead = head->next;
    
    while(curr && curr->next){
        prev->next = curr->next;
        prev = curr;
        
        Node *next = curr->next->next;
        curr->next->next = curr;
        
        curr = next;
    }
    
    prev->next = curr;
    return newhead;
}
// Recursive
Node* pairWiseSwap(Node* head){
    if (head == NULL || head->next == NULL) 
        return head; 
    Node* curr = head->next->next;
    head->next->next = head;
    Node* newhead = head->next;
    head->next = pairWiseSwap(curr);
    return newhead;
}
