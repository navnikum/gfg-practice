https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
// sliding window
#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> arr, int n, int sum) 
{ 
    int cur_sum = arr[0], start = 0, i = 1;
    while(i <= n) { 
        while (cur_sum > sum && start < i - 1)
            cur_sum -= arr[start++];
 
        if (cur_sum == sum) { 
            cout << start+1 << " " << i<<endl; 
            return 1; 
        } 
        if (i < n) 
            cur_sum += arr[i]; 
        i++;
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
