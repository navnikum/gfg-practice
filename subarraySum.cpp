https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
// sliding window
#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> a, int n, int k){
    
    int cur_sum = 0, start = 0, i = 0;
    while(i < n){
        cur_sum += a[i++];
        
        while(cur_sum > k and start < i){
            cur_sum -= a[start++];
        }
        
        if (cur_sum == k) { 
            cout << start+1 << " " << i<<endl; 
            return 1; 
        }
    }
    // If we reach here, then no subarray 
    cout << -1 << endl; 
    return 0; 
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
        subArraySum(a, n, k);
    }
	return 0;
}
