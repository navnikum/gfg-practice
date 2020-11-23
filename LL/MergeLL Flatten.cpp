// Recursive
Node* merge(Node* h1, Node* h2) {
    if(!h1) return h2;
    if(!h2) return h1;
    if(h1->data < h2->data){
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else{
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

// iterative
Node* mergeUtil(Node* h1, Node* h2) {
    if(!h1->next){
        h1->next = h2;
        return h1;
    }
    Node *curr1 = h1, *next1 = h1->next; 
    Node *curr2 = h2, *next2 = h2->next;
    while(next1 && curr2){
        if(curr1->data <= curr2->data && curr2->data <= next1->data){
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            
            curr1 = next1;
            curr2 = next2;
        }
        else{
            if(next1->next){
                next1 = next1->next;
                curr1 = curr1->next;
            }
            else{
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}
Node* merge(Node* h1, Node* h2) {
    if(!h1) return h2;
    if(!h2) return h1;
    if(h1->data < h2->data)
        return mergeUtil(h1, h2);
    else
        return mergeUtil(h2, h1);
}


// FLATTEN Linked List {right, down} pointers
Node* merge(Node* a, Node* b){
    if(!a)   return b;
    if(!b)   return a;
    Node* res;
    if(a->data < b->data){
        res = a;
        res->bottom = merge(a->bottom, b);
    }
    else{
        res = b;
        res->bottom = merge(a, b->bottom);
    }
    res->next = b;
    return res;
}
Node *flatten(Node *root){
    // base case
    if(root==NULL || root->next == NULL)    return root;
    return merge(root, flatten(root->next));
}
