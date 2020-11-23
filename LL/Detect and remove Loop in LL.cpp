// Hashing O(n) O(1)
bool detectLoop(struct Node* h) {
    //hashing
    unordered_set<Node* > s;
    while(h != NULL){
        if(s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}
// O(n) O(1) using temp node as flag
bool detectLoop(struct Node* h) {
    Node *temp = new Node;
    while(h != NULL){
        if(h->next == NULL) return false;
        if(h->next == temp) return true;
        Node* nx = h->next;
        h->next = temp;
        h = nx;
    }
    return false;
}
// Floyd's Cycle finding O(n) O(1)
bool detectLoop(struct Node* h) {
    Node *slow, *fast;
    slow = fast = h;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

// Remove loop in LL
void detectLoop(Node* head) {
    if(head == NULL || head->next == NULL)
        return;
    Node *slow, *fast;
    slow = fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow == fast){
        slow = head;
        if(slow == fast){
            // loop ends at head move only fast pointer
            while(fast->next != slow)   
                fast = fast->next;
        }
        else{
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}
