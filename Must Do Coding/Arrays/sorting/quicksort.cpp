// O(nlogn)
int partition(vector<int>& v, int left, int right) {
    int pivot = v[left], l = left + 1, r = right;
    while (l <= r) {
        // descending order
        /*if (v[l] < pivot && pivot < v[r]) swap(v[l++], v[r--]);
        if (pivot <= v[l])  l++;
        if (pivot >= v[r])  r--;*/
        
        // ascending order
        if (v[l] > pivot && pivot > v[r]) swap(v[l++], v[r--]);
        if (pivot >= v[l])  l++;
        if (pivot <= v[r])  r--;
        
    }
    swap(v[left], v[r]);
    return r;
}

void quickSort(vector<int>& arr, int low, int high) {  
    if (low < high){  
        int pi = partition(arr, low, high);  

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}
