// O(m+n) O(m+n)
vector<int> merge(vector<int> arr1, vector<int> arr2, int n, int m){ 
    vector<int> arr(m+n);
    int i,j,k;
    i=j=k=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while(i<n){
        arr[k++] = arr1[i++];
    }
    while(j<m){
        arr[k++] = arr2[j++];
    }
    return arr;
} 
// O(m+n) O(1)
vector<int> merge(vector<int> arr1, vector<int> arr2, int n, int m){ 
    arr1.resize(m+n);
    int i,j,k;
    i=n-1; j=m-1; k=m+n-1;
    while(i>=0 && j>=0){
        if(arr1[i] > arr2[j])
            arr1[k--] = arr1[i--];
        else
            arr1[k--] = arr2[j--];
    }
    while(j>=0){
        arr1[k--] = arr2[j--];
    }
    return arr1;
} 

// # In-place merge two sorted arrays
// O(mn) O(1)
void merge(vector<int> X, vector<int> Y, int n, int m){
  for (int i = 0; i < n;  i++){
		if (X[i] > Y[0]){
			swap(X[i], Y[0]);
			int first = Y[0];
			// move Y[0] to its correct position to maintain sorted
			// order of Y[]. Note: Y[1..n-1] is already sorted
			for (int k = 1; k < m && Y[k] < first; k++){
				Y[k - 1] = Y[k];
			}
			Y[k - 1] = first;
		}
	}
}





