// O(n) O(n)
#include <bits/stdc++.h>
using namespace std;

string removeDups(string S) {
    set<char> s;
    int k = S.size(), t=0;
    s.insert(S[0]);
    for(int i=1; i<k; i++){
        if(s.count(S[i]) == 0){
            S[++t] = S[i];
            s.insert(S[i]);
        }
    }
    return S.erase(t+1);
}

int main() {
	int t;  cin>>t;
	while(t--){
	    string s;   cin>>s;
	    cout<<removeDups(s)<<endl;
	}
	return 0;
}

/* Input :  3
            geeksforgeeks
            gfg
            zvvo
   Output : geksfor
            gf
            zvo */
            
