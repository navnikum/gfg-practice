// O(n^2) O(1)
#include <bits/stdc++.h>
using namespace std;
string fun(string str){
	int n = str.size();
	int s,e, gs=0, ge=0;
	for(int i=0; i<n; i++){
	    //even length
	    s = i-1, e = i;
	    while(s >= 0 && e<n && str[s]==str[e]){
	        if(e-s > ge-gs)
	            ge = e, gs = s;
	        s--;
	        e++;
	    }
	    //odd length
	    s = i-1, e = i+1;
	    while(s >= 0 && e<n && str[s]==str[e]){
	        if(e-s > ge-gs)
	            ge = e, gs = s;
	        s--;
	        e++;
	    }
	}
	return str.substr(gs, ge-gs+1);
}
int main() {
	int t;  cin>>t;
	while(t--){
	    string s;   cin>>s;
	    cout<<fun(s)<<endl;
	}
	return 0;
}
