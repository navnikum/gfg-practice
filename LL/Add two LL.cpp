// Case 1: Least significant head
Node* addTwoLists(Node* first, Node* second){
    Node *res, *prev;
    res = prev = NULL;
    int sum, carry = 0;
    while(first || second){
        sum = carry + (first? first->data:0) + (second? second->data:0);
        carry = (sum>=10) ? 1 : 0;
        sum = sum%10;
        Node *sumNode = new Node(sum);
        if(res == NULL) // empty
            res = sumNode;
        else
            prev->next = sumNode;
        
        prev = sumNode;
        if(first)   first = first->next;
        if(second)  second = second->next;
    }
    if(carry > 0)
        prev->next = new Node(carry);
    
    return res;
}

// case 2: Most significant head
Node* addTwoLists(Node* l1, Node* l2) {
    stack<int> s1,s2;
    while(l1) s1.push(l1->data), l1=l1->next;
    while(l2) s2.push(l2->data), l2=l2->next;

    Node *res = NULL;
    int sum = 0, carry = 0;
    while(!s1.empty() || !s2.empty()){
        int a=0, b=0; 
        if(!s1.empty()) a=s1.top(), s1.pop();
        if(!s2.empty()) b=s2.top(), s2.pop();
        sum = carry + a + b;
        carry = (sum>=10) ? 1 : 0;
        sum = sum%10;
        // push(&res, sum);
        Node *sumNode = new Node(sum);
        sumNode->next = res;
        res = sumNode;
    }
    // push(&res, carry);
    if(carry != 0){
        Node* tmp = new Node(carry);
        tmp->next = res;
        res = tmp;
    }
    return res;
}
