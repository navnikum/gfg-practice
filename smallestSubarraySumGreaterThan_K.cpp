// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0

// sliding window

#include <bits/stdc++.h>
using namespace std;

int subarray(vector<int> a, int n, int k){
    int minl = n+1;
    
    int cur_sum = 0, start = 0, i = 0;
    while(i < n){
        cur_sum += a[i++];
        
        while(cur_sum > k and start < i){
            minl = min(minl, i - start);
            cur_sum -= a[start++];
        }
    }
    return minl;
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
        cout<<subarray(a, n, k)<<endl;
    }
	return 0;
}
