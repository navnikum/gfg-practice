int kthSmallest(vector<int>& v, int n, int k){
    sort(v.begin(), v.end());
    return v[k-1];
} 

// maxHeap O(n+klogn)
int kthSmallest(vector<int>& v, int n, int k){
    priority_queue<int, vector<int> > pq;
    for(int i=0; i<n; i++)  pq.push(v[i]);
    while(pq.size() > k)    pq.pop();
    
    return pq.top();
}

// Partitioning O(n)
// according to the index of pivot, we will know whther the kth largest element is to the left or right of pivot or just itself.
/*
In average, this algorithm reduces the size of the problem by approximately one half after each partition, 
giving the recurrence T(n) = T(n/2) + O(n) with O(n) being the time for partition.
The solution is T(n) = O(n), which means we have found an average linear-time solution. 
However, in the worst case, the recurrence will become T(n) = T(n - 1) + O(n) and T(n) = O(n^2)
*/

int partition(vector<int>& v, int left, int right) {
    int pivot = v[left], l = left + 1, r = right;
    while (l <= r) {
        if (v[l] < pivot && pivot < v[r]) swap(v[l++], v[r--]);
        if (pivot <= v[l])  l++;
        if (pivot >= v[r])  r--;
    }
    swap(v[left], v[r]);
    return r;
}
int kthLargest(vector<int>& v, int n, int k) {
    k = (n-k+1); // kth largest is (n-k+1)th smallest in array
    int left = 0, right = n-1, kth;
    while (true) {
        int idx = partition(v, left, right);
        if (idx == k-1) {
            kth = v[idx];
            break;
        }
        else if (idx < k-1)  left = idx + 1;
        else    right = idx - 1;
    }
    return kth;
}
