#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Queue{
    public:
    Node *front, *rear;
    Queue(){
        front = rear = NULL;
    }
    void push(int x){
        // empty, full, others
        Node *node = new Node(x);
        if(rear == NULL){
            front = rear = node;
            return;
        }
        rear->next = node;
        rear = node;
    }
    void pop(){
        //empty, others
        if(front == NULL)   return;
        Node* node = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        delete(node);
    }
};

int main(){
   Queue q; 
    q.push(10); 
    q.push(20); 
    q.pop(); 
    q.pop(); 
    q.push(30); 
    q.push(40); 
    q.push(50); 
    q.pop(); 
    cout << "Queue Front : " << (q.front)->data << endl; 
    cout << "Queue Rear : " << (q.rear)->data; 
    return 0;
}

