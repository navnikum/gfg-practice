// O(n^2)
int findElement(vector<int>& arr, int n){
    int i,j,k;
    for(i=1; i<n-1; i++){
        for(j=0; j<i; j++)  
            if(arr[j] >= arr[i])    break;
        for(k=i+1; k<n; k++)
            if(arr[i] >= arr[k])    break;
        if(k == n && j == i)
            return arr[i];
    }
    return -1;
}

// O(n)
vector<int> rmin(n);
    rmin[n-1] = INT_MAX;
    int i, lmax = INT_MIN;
    for(i=n-2; i>= 0; i--) rmin[i] = min(rmin[i+1], arr[i+1]);     
    for(int i=1; i<n-1; i++){
        if(lmax < arr[i] && rmin[i] > arr[i])
            return arr[i];
        lmax = max(lmax, arr[i]);
    }
    return -1;
}
