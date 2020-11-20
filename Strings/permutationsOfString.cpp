// backtracking O(n*n!)
#include <bits/stdc++.h>
using namespace std;
set<string> ans;
void permutations(string s, int l, int r){
    if(l == r){
        ans.insert(s);
        return;
    }
    else{
        for(int i=l; i<=r; i++){
            swap(s[i],s[l]);
            permutations(s, l+1, r);
            swap(s[i],s[l]);
        }
    }
}
int main() {
	int t; cin>>t;
	while(t--){
	    ans.clear();
	    string s;
	    cin>>s;
	    int k=s.size();
	    permutations(s, 0, k-1);
	    for(auto it: ans)
	        cout<<it<<" ";
	    cout<<endl;
	}
	return 0;
}
