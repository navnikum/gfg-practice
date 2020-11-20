// O(n^3)
bool isTriplet(vector<int>& a, int n) {
    int i, j, k;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            for(k=j+1; k<n; k++){
                int x = a[i] * a[i], y = a[j] * a[j], z = a[k] * a[k];
                if (x == y + z || y == x + z || z == x + y) 
                    return true;
            }
        }
    }
    return false;
}

// O(n^2) Two pointer
bool isTriplet(vector<int>& a, int n) {
    int i, l, r;
    for(i=0; i<n; i++)  a[i] = pow(a[i], 2);
    sort(a.begin(), a.end());
    for(i=n-1; i>=2; i--){
        l=0, r = i-1;
        while(l < r){
            if(a[l]+a[r] == a[i])   return true;
            else if(a[l]+a[r] < a[i])   l++;
            else
                r--;
        }
    }
    return false;
}
