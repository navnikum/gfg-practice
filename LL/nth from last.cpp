//
int getNthFromLast(Node *head, int n){
    int l = LLsize(head);
    Node *curr = head;
    // (l+1-n)th from beginning
    for(int i=1; i< (l+1-n); i++)
        curr = curr->next;
    return curr->data;
}

//
int getNthFromLast(Node *head, int n){    
    Node *ptr1, *ptr2;
    ptr1 = ptr2 = head;
    for(int i=0; i<n; i++){
        if(ptr2 == NULL)    return -1;
        ptr2 = ptr2->next;
    }
    if(ptr2 == NULL){
        head = head->next;
        if(head != NULL)    return ptr1->data;
    }
    else{
        while(ptr2 != NULL){
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        return ptr1->data;
    }
}
