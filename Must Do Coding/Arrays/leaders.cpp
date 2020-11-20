// O(n^2)
void printLeaders(vector<int> arr, int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]<arr[j])
                break;
        }
        if(j == n)  cout<<arr[i]<<" ";
    }
}

// O(n)
void printLeaders(vector<int> arr, int n){
    int maxFromRight = arr[n-1];
    cout<<maxFromRight<<" ";
    for(int i= n-2; i>=0; i--){
        if(arr[i] >= maxFromRight){
            maxFromRight = arr[i];
            cout<<maxFromRight<<" ";
        }
    }
} 
