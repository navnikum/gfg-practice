/*
Input: arr[] = {1, 2, 3, 4, 5, 6, 7} 
Output: arr[] = {7, 1, 6, 2, 5, 3, 4}
Input: arr[] = {1, 2, 3, 4, 5, 6} 
Output: arr[] = {6, 1, 5, 2, 4, 3} */

// O(n) O(n)
void rearrange(vector<int>& arr, int n){
    vector<int> t(n);
    bool flag = 0;
    int s=0, l=n-1;
    for(int i=0; i<n; i++){
        if(flag)
            t[i] = arr[s++];
        else
            t[i] = arr[l--];
        flag = !flag;
    }
    arr = t;
}

// O(n) O(1)
void rearrange(vector<int>& arr, int n){
    int minidx=0, maxidx=n-1, maxelem = arr[n-1]+1;
    for(int i=0; i<n; i++){
        if(i % 2 == 0)
            arr[i] += (arr[maxidx--]%maxelem)*maxelem;
        else
            arr[i] += (arr[minidx++]%maxelem)*maxelem;
    }
    for(int i=0; i<n; i++)
        arr[i] = arr[i]/maxelem;
}
