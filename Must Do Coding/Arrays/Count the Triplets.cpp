// count the triplets (Two Pointers)
// 2 sum , 3 sum, count triplet
// https://practice.geeksforgeeks.org/problems/count-the-triplets
// O(n^2) O(1)
int countTriplet(int arr[], int n){
    sort(arr, arr+n);
    int cntTriplets = 0;
    for(int i= n-1; i>=2; i--){
        int j=0, k=i-1;
        int target = arr[i];
        while(j < k){
            if(arr[j]+arr[k] == target){
                cntTriplets++;
                j++, k--;
            }
            else if(arr[j]+arr[k] < target)
                j++;
            else
                k--;
        }
    }
    return cntTriplets;
}
