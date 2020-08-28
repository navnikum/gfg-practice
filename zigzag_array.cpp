https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0

// one pass bubble sort swap with flag

#include <bits/stdc++.h>
using namespace std;
void printarray(vector<int> a, int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void zigzag(vector<int> &a, int n){
    // '<' : true ; '>' : false
    bool order = true;
    for(int i = 0; i < n-1; i++){
        if(order){
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        }
        else{
            if(a[i] < a[i+1])
                swap(a[i], a[i+1]);
        }
        order = not order;
    }
}

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a;
        for(int i = 0; i < n; i++){
            int p ;
            cin>>p;
            a.push_back(p);
        }
        zigzag(a, n);
        printarray(a, n);
    }
	return 0;
}
