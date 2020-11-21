// Method1 break between kth (k+1)th node
void rotate(Node** head, int k){
    if(k==0)    return;
    Node *curr = (*head), *kth;
    int cnt = 1;
    while(cnt < k && curr)  curr= curr->next, cnt++;
    if(curr == NULL)    return;
    kth = curr;
    while(curr->next != NULL)   curr= curr->next;
    curr->next = (*head);
    (*head) = kth->next;
    kth->next = NULL;
}

// Method2 Make circular LL and break at kth node
void rotate(Node** head, int k){
    if(k==0)    return;
    Node *curr = (*head);
    while(curr->next != NULL)   curr= curr->next;
    curr->next = (*head);
    curr = (*head);
    for(int i=0; i< k-1; i++)
        curr = curr->next;
    
    (*head) = curr->next;
    curr->next = NULL;
}
