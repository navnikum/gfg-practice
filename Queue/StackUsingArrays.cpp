#include<bits/stdc++.h>
using namespace std;
const int N = 10;
class Stack{
    int A[N];
    int top;
    public :
    Stack(){
        top = -1;
    }
    bool isEmpty(){
        if(top == -1)
            return 1;
        return 0;
    }
    bool isFull(){
        if(top == N)
            return 1;
        return 0;
    }
    int Top(){
        if(top == -1)
            return -1;
        return A[top];
    }
    void push(int x){
        // empty, full, other
        if(isEmpty()){
            top = 0;
        }
        if(isFull()){
            return;
        }
        else
            top = (top + 1)%N;
        A[top] = x;
    }
    void pop(){
        // empty, one element, other
        if(isEmpty()){
            return;
        }
        else if(top == 0){
            top = -1;
        }
        else
            top = (top + N - 1)%N;
    }
    void Print(){
        int cnt = (top)% N + 1;
        for(int i=0; i< cnt; i++){
            int idx = i;
            cout<<A[idx]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack Q; // creating an instance of Queue. 
    Q.push(5);  Q.Print();  
    Q.push(4);  Q.Print();  
    Q.push(6);  Q.Print();
    Q.pop();	Q.Print();
    Q.push(8);  Q.Print();
    return 0;
}

