// O(n^3)
bool distinct(string S, int l, int r){
    set<char> s;
    for(int i=l; i<=r; i++){
        if(s.count(S[i]) != 0)
            return false;
        s.insert(S[i]);
    }
    return true;
}
int longestUniqueSubstr(string str) {
    int n = str.size(), res = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(distinct(str, i, j))
                res = max(res, j-i+1);
        }
    }
    return res;
}

// O(n^2)Slising window
int longestUniqueSubstr(string S) {
    int n = S.size(), res = 0;
    for(int i=0; i<n; i++){
        set<char> s;
        for(int j=i; j<n; j++){
            if(s.count(S[j]) != 0)
                break;
            else{
                s.insert(S[j]);
                res = max(res, j-i+1);
            }
        }
        s.erase(S[i]);
    }
    return res;
}

// O(n) lastIdx array 
#define N 256
int longestUniqueSubstr(string S) {
    int n = S.size(), res = 0;
    vector<int> lastIdx(N, -1);
    int i=0, j;
    for(j=0; j<n; j++){
        i = max(i, lastIdx[S[j]] + 1);
        res = max(res, j-i+1);
        lastIdx[S[j]] = j;
    }
    return res;
}

