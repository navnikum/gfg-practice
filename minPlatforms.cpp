https://practice.geeksforgeeks.org/problems/minimum-platforms/0

// increasing time at the platform : O(nlogn) time, O(1) space

#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int> a, vector<int> d, int n){
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    int pf = 1, maxPf = 1;
    int i = 1, j = 0;
    while(i < n and j < n){
        if(a[i] <= d[j]){
            pf++;
            i++;
        }
        else{
            pf--;
            j++;
        }
        maxPf = max(maxPf, pf);
    }
    return maxPf;
}

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a,d;
        for(int i = 0; i < n; i++){
            int p ;
            cin>>p;
            a.push_back(p);
        }
        for(int i = 0; i < n; i++){
            int p ;
            cin>>p;
            d.push_back(p);
        }
        cout<<minPlatforms(a, d, n)<<endl;
    }
	return 0;
}
