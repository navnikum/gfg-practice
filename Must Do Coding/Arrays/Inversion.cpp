// O(n^2) O(1)
long inversionCount(vector<long> arr, long n){
    int invcnt = 0;
    for(int i=0; i<n-1; i++)
        for(int j=i+1.; j<n; j++)
            if(arr[j] < arr[i])
                invcnt++;
    
    return invcnt;
}

// STL O(n^2) O(n)
long inversionCount(vector<long> arr, long n){
    multiset<long> s1;
    s1.insert(arr[0]);
    int invcnt = 0;
    for(int i=1; i<n; i++){
        s1.insert(arr[i]);
        invcnt += distance(s1.upper_bound(arr[i]), s1.end());
    }
    return invcnt;
}
// O(nlogn)
long inversionCount(vector<long> arr, long n){
    vector<long> v;
    int invcnt = 0;
    for(int i=0; i<n; i++){
        int idx = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
        invcnt += i-idx;
        v.insert(v.begin()+idx, arr[i]);
    }
    return invcnt;
}

// Modified MergeSort O(nlogn)
#include<bits/stdc++.h>
using namespace std;
long long int ans;

int merge(vector<int>& a, int l, int m, int h){
	int i, j, k;
	int n1 = m-l+1, n2 = h-m;
	vector<int> t1(n1), t2(n2);
	for (i = 0; i < n1; i++) 	t1[i] = a[l + i]; 
	for (j = 0; j < n2; j++) 	t2[j] = a[m + 1+ j];
	
	i=j=0;  k=l;
	
	while(i<n1 && j<n2){
		if(t1[i] <= t2[j])
			a[k++] = t1[i++];
		else{
			a[k++] = t2[j++];
			ans += (n1-i);      // Modification 'HACK'
		}
	}
	
	while(i<n1)
		a[k++] = t1[i++];
	
	while(j<n2)
		a[k++] = t2[j++];

}

int mergesort(vector<int>& a, int l, int h){
	if(l < h){
		int m = l + (h-l)/2;
		mergesort(a, l, m);
		mergesort(a, m+1, h);
		
		merge(a, l, m , h);
	}
}
	
int main(){
	int n;  cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;++i)	cin >> a[i];
    ans = 0;
	mergesort(a, 0, n-1);
	cout << ans << endl;

return 0;
}
