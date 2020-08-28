https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0

// minimize diff between max_elem and min_elem in subarray

#include <bits/stdc++.h>
using namespace std;

int chocolate_min_maxDiff(vector<int> a, int n, int k){
    if (k == 0 || n == 0) 
        return 0;
        
    if (n < k) 
        return -1;
        
    sort(a.begin(), a.end());
    int minDiff = INT_MAX;
    for(int i = 0; i+k-1 < n ; i++){
        int diff = a[i+k-1] - a[i];
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}
int main() {
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a;
        for(int i = 0; i < n; i++){
            int p ;
            cin>>p;
            a.push_back(p);
        }
        cin>>m;
        cout<<chocolate_min_maxDiff(a, n, m)<<endl;
    }
	return 0;
}
