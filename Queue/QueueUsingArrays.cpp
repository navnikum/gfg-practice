#include<bits/stdc++.h>
using namespace std;
const int N = 10;
class Queue{
    int A[N];
    int front, rear;
    public :
    Queue(){
        front = -1; rear = -1;
    }
    bool isEmpty(){
        if(front == -1 && rear == -1)
            return 1;
        return 0;
    }
    bool isFull(){
        if(front == (rear+1)%N)
            return 1;
        return 0;
    }
    int Front(){
        if(front == -1)
            return -1;
        return A[front];
    }
    void push(int x){
        // empty, full, other
        if(isEmpty()){
            front = rear = 0;
        }
        if(isFull()){
            return;
        }
        else
            rear = (rear + 1)%N;
        A[rear] = x;
    }
    void pop(){
        // empty, one element, other
        if(isEmpty()){
            return;
        }
        else if(front == rear){
            rear = front = -1;
        }
        else
            front = (front + 1)%N;
    }
    void Print(){
        int cnt = (rear-front+N)% N + 1;
        for(int i=0; i< cnt; i++){
            int idx = (front+i)%N;
            cout<<A[idx]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue Q; // creating an instance of Queue. 
    Q.push(5);  Q.Print();  
    Q.push(4);  Q.Print();  
    Q.push(6);  Q.Print();
    Q.pop();	Q.Print();
    Q.push(8);  Q.Print();
    return 0;
}
