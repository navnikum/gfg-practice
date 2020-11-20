// O(n^2)

//O(n)
void zigZag(vector<int>& arr, int n) { 
	bool flag = true; // < : T ; > : F
	for (int i=0; i< n-1; i++){ 
		if (flag){
			if (arr[i] > arr[i+1]) 
				swap(arr[i], arr[i+1]); 
		} 
		else{ 
			if (arr[i] < arr[i+1]) 
				swap(arr[i], arr[i+1]); 
		} 
		flag = !flag;
	} 
} 
