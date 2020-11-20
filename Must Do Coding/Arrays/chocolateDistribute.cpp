// O(nlogn) O(1)
int findMinDiff(vector<int>& arr, int n, int m){
    if(n==0 || m==0)  return 0;
    if(n < m)   return -1;
    int minDiff = INT_MAX;
    sort(arr.begin(),arr.end());
    for(int i=0; i< (n-m+1); i++)
        minDiff = min(minDiff, (arr[m-1+i]-arr[i]));
    return minDiff;
}
