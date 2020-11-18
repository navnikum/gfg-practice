#include <bits/stdc++.h>
using namespace std;
// O(n^2) O(1)
vector<int> solve(vector<int> v, int n, int k){
    vector<int> ans(2, -1);
    int csum=0;
    for(int i=0; i<n; i++){
        csum = v[i];
        for(int j=i+1; j<=n; j++){
            if(csum == k){
                ans[0] = i, ans[1] = j-1;
                return ans;
            }
            if(csum > k || j == n)  break;
            csum += v[j];
        }
    }
    return ans;
}
// O(n) O(n)
vector<int> solve(vector<int> v, int n, int k){
    vector<int> ans(2, -1);
    // map stores <subarray sum start from 0, endidx>
    unordered_map<int, int> mp;
    int csum=0;
    for(int i=0; i<n; i++){
        csum += v[i];
        if(csum == k){
            ans[0] = 0, ans[1] = i;
            break;
        }
        if(mp.find(csum-k) != mp.end()){
            ans[0] = mp[csum-k]+1, ans[1] = i;
            break;
        }
        mp[csum] = i;
    }
    return ans;
}
// O(n) O(1)
vector<int> solve(vector<int> v, int n, int k){
    vector<int> ans(2, -1);
    // newTar = k + l*offset
    int csum, i, start=0, targetSum=k;
	csum = v[0];
  	
	for (i = 1; i <= n; i++) { 
		while (csum > targetSum && start < i-1) { 
			csum -= (v[start++]); 
		} 
		
		if (csum == targetSum) { 
			ans[0] = start, ans[1] = i-1;
            break;
		} 
      
		if (i < n) 
			csum += v[i]; 
	} 
    return ans;
}
// handle -ve with offset
vector<int> solve(vector<int> v, int n, int k){
    vector<int> ans(2, -1);
    // newTar = k + l*offset
    int minEle, offset, csum, i, start=0, targetSum=k;
    minEle  = *min_element(v.begin(), v.end());
  	offset = abs(minEle);
	csum = (v[0] + offset);
  	
	for (i = 1; i <= n; i++) { 
      	int x = csum - (i - start) * offset;
		while (x > targetSum && start < i-1) { 
			csum -= (v[start++] + offset); 
		} 
		
		if (x == targetSum) { 
			ans[0] = start, ans[1] = i-1;
            break;
		} 
      
		if (i < n) 
			csum += (v[i] + offset); 
	} 
    return ans;
}

int main() {
	int t;  cin>>t;
	while(t--){
	    int n, s;
	    cin>>n>>s;
	    vector<int> a(n);
	    for(int i=0; i<n; i++)  cin>>a[i];
	    vector<int> res = solve(a, n, s);
	    if(res[0] == -1){
	        cout << res[0];
	        break;
	    }
	    cout<<res[0]+1<<" "<<res[1]+1<<endl;
	}
	return 0;
}
