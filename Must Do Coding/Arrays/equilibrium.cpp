// O(n^2)
int equilibriumPoint(vector<int> a, int n) {
    int lsum, rsum, i, j;
    for(i=0; i<n; i++){
        lsum=0, rsum=0;
        for(j=0; j<i; j++)  lsum += a[i];
        for(j=i+1; j<n; j++)    rsum += a[i];
        if(lsum == rsum)
            return (i+1);
    }
    return -1;
}

// O(n)
int equilibriumPoint(vector<int> a, int n) {
    int lsum=0, sum=0, i, j;
    for(i=0; i<n; i++)  sum += a[i];
    for(i=0; i<n; i++){
        sum -= a[i];
        if(lsum == sum)
            return (i+1);
        lsum += a[i];
    }
    return -1;
}
