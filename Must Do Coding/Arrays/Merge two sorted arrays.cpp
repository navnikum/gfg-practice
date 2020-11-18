// O(m+n) O(m+n)
vector<int> merge(vector<int> arr1, vector<int> arr2, int n, int m){ 
    vector<int> arr(m+n);
    int i,j,k;
    i=j=k=0;
    while(i<n && j<m){
        if(arr1[i] <= arr2[j])
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

// O(m+n) O(1)
//https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
/*Suppose we we want to convert A to B and there is also a constrain that we can recover number A any 
time without using other variable.

To achieve this we chose a number N which is greater than both numbers and add B*N int A.
so A --> A+B*N

To get number B out of (A+B*N) 
we devide (A+B*N) by N (A+B*N)/N = B.

To get number A out of (A+B*N) 
we take modulo with N (A+B*N)%N = A.

-> In short by taking modulo we get old number back and taking divide we new number.*/
void mergeArray(vector<int> a, vector<int> b, int n, int m){
	int mx = *max_element(a.begin(), a.end());
  	mx = max(mx, *max_element(b.begin(), b.end()));
  	mx++;

	int i = 0, j = 0, k = 0;
	while (i < n && j < m && k < (n + m)) {
		int e1 = a[i] % mx;
		int e2 = b[j] % mx;
		if (e1 <= e2) {
			if (k < n)
				a[k] += (e1 * mx);
			else
				b[k - n] += (e1 * mx);
			i++;
          	k++;
		}
		else {
			if (k < n)
				a[k] += (e2 * mx);
			else
				b[k - n] += (e2 * mx);
			j++;
          	k++;
		}
	}
	
	while (i < n) {
		int el = a[i] % mx;
		if (k < n)
			a[k] += (el * mx);
		else
			b[k - n] += (el * mx);
		i++;
		k++;
	}
	
	while (j < m) {
		int el = b[j] % mx;
		if (k < n)
			b[k] += (el * mx);
		else
			b[k - n] += (el * mx);
		j++;
		k++;
	}
	
	// finally update elements by dividing with maximum element
	for (int i = 0; i < n; i++)
		a[i] = a[i] / mx;

	// finally update elements by dividing with maximum element
	for (int i = 0; i < m; i++)
		b[i] = b[i] / mx;

	return;
}



