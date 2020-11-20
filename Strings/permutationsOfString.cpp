// backtracking O(n*n!)
void permutations(string s, int l, int r){
    if(l == r){
        ans.push_back(s);
        return;
    }
    else{
        for(int i=l; i<=r; i++){
            swap(s[l], s[i]);
            permutations(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}
