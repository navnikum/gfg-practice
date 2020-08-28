https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0

// modified circular kadane

#include <bits/stdc++.h>
using namespace std;

int circularKadane(vector<int>a, int n){
    if (n == 1) 
        return a[0];
        
    int curmax, curmin, farmax, farmin, sum;
    curmax = farmax = curmin = farmin = sum = a[0];
    for(int i = 1; i < n; i++){
        sum += a[i];
        // maxSum subarray
        curmax = max(a[i], curmax+a[i]);
        farmax = max(farmax, curmax);
        
        //minsum subarray;
        curmin = min(a[i], curmin+a[i]);
        farmin = min(farmin, curmin);
    }
    if (farmin == sum) 
		return farmax;
    return max(farmax, sum-farmin);
}

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a;
        for(int i = 0; i < n; i++){
            int k ;
            cin>>k;
            a.push_back(k);
        }
        cout<<circularKadane(a, n)<<endl;
    }
	
	return 0;
}
