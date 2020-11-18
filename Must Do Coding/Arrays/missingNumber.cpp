
int MissingNumber(vector<int>& a, int n) {
    /*int tot = 1;
    for(int i=2; i<=(n+1); i++){
        tot += i;
        tot-= a[i-2];
    }
    return tot;*/
    int x1 = a[0], x2 = 1;
    for(int i=1; i<n; i++)
        x1 = x1 ^ a[i];
    for(int j=2; j<=(n+1); j++)
        x2 = x2 ^ j;
    return x1 ^ x2;
}
