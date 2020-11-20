// O(n) O(1)
void sortArr(vector<int>& arr, int n){
    int cnt0, cnt1, cnt2, i;
    cnt0=cnt1=cnt2=0;
    for(i=0; i<n; i++){
        if(arr[i] == 0) ++cnt0;
        if(arr[i] == 1) ++cnt1;
        if(arr[i] == 2) ++cnt2;
    }
    i=0;
    while(cnt0-- > 0) arr[i++] = 0;
    while(cnt1-- > 0) arr[i++] = 1;
    while(cnt2-- > 0) arr[i++] = 2;
} 

// Dutch National Flag [ {0}0-l, {1}l-m, {unknown}m-h, {2}h-n] : 3way partitioning
void sortArr(vector<int>& arr, int n){
    int l,m,h;
    l=m=0, h=n-1;
    while(m<=h){
        if(arr[m] == 0)     swap(arr[l++], arr[m++]);
        else if(arr[m] == 1)    m++;
        else if(arr[m] == 2)    swap(arr[m], arr[h--]);
    }
} 
