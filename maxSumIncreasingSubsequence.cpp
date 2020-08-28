// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

// LIS variation : sum as a criteria instead of length

#include <bits/stdc++.h>
using namespace std;

int msIS(vector<int>a, int n){
    vector<int> msis(n);
    for(int i = 0; i < n; i++)
        msis[i] = a[i];
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i])
                msis[i] = max(msis[i], msis[j] + a[i]);
        }
    }
    return *max_element(msis.begin(), msis.end());
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
    cout<< msIS(a, n)<< endl;
    }
	return 0;
}
