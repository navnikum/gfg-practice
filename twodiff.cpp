https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0

#include <bits/stdc++.h>
using namespace std;

// with sorting 
int twodiff(vector<int> a, int n, int k){
    sort(a.begin(), a.end());
    int i = 0,j = 1;
    while(i < n and j < n){
        if(i != j and a[j]-a[i] == k)
            return 1;
        else if(a[j]-a[i] < k)
            j++;
        else
            i++;
    }
    return -1;
}
// with hashing
int twodiff(vector<int> a, int n, int k){
    unordered_set<int> s;
    for(int i = 1; i < n; i++)
        s.insert(a[i]);
    
    for(int i = 0; i < n; i++){
        int key = a[i] + k;
        if(s.find(key) != s.end())
            return 1;
    }
    return -1;
}

int main() {
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a;
        for(int i = 0; i < n; i++){
            int p ;
            cin>>p;
            a.push_back(p);
        }
        cout<<twodiff(a, n, k)<<endl;
    }
	return 0;
}
