void reverse(vector<int>& v, int n, int k){
    int i, l, r;
    for(i=0; i<n; i+=k){
        l=i, r = min(l+k-1, n-1);
        reverse(v.begin()+l, v.begin()+(r+1));
    }
}
