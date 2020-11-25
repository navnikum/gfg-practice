#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin>>q;
    stack<int> s1, s2;
    while(q--){
        /*
        1 x: Enqueue element  into the end of the queue.
        2: Dequeue the element at the front of the queue.
        3: Print the element at the front of the queue.
        */
        int ch; cin>>ch;
        if(ch == 1){
            int x;  cin>>x;
            s1.push(x);
        }
        else if(ch == 2){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());  s1.pop();
                }
            }
            s2.pop();           
        }
        else if(ch == 3){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());  s1.pop();
                }
            }
            cout<<s2.top()<<endl;
        }
    }  
    return 0;
}
