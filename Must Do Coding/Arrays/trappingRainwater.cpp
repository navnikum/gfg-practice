// O(n^2) O(1)
int maxWater(vector<int> arr, int n){
    int i,j, a, b, water = 0;
    for(i=1; i<n-1; i++){
        a = b = arr[i];
        for(j=0; j<i; j++)  a = max(a, arr[j]);
        for(j=i+1; j<n; j++)    b = max(b, arr[j]);
        water += (min(a,b) - arr[i]);
    }
    return water;
} 

// O(n) O(n)
int maxWater(vector<int> arr, int n){
    int i,water = 0;
    vector<int> l(n), r(n);
    // l : max from 0 to i , r : max from i to n
    l[0] = arr[0], r[n-1] = arr[n-1];
    
    for(i=1; i<n; i++)  l[i] = max(l[i-1], arr[i]);
    for(i=n-2; i>=0; i--)   r[i] = max(r[i+1], arr[i]);
    
    for(i=0; i<n; i++)
        water += (min(l[i],r[i]) - arr[i]);
    
    return water;
} 

// O(n) O(1)
int maxWater(vector<int> arr, int n){
    int l=0, h= n-1, water=0;
    int lmax=0, rmax=0;
    while(l <= h){
        if(arr[l] < arr[h]){
            lmax = max(lmax, arr[l]);
            water += lmax-arr[l];
            l++;
        }
        else{
            rmax = max(rmax, arr[h]);
            water += rmax-arr[h];
            h--;
        }
    }
    return water;
} 
