// O(n^2)
int findPlatform(vector<int> a, vector<int> d, int n){
    int pf , res=1, i, j;
    for(i=0; i<n; i++){
        pf=1;
        for(j=i+1; j<n; j++){
            // i ********    *********
            // j   *******  ********
            if( (a[i]<=a[j] && a[j]<=d[i]) || (a[j]<=a[i] && a[i]<=d[j]) )
                pf++;
        }
        res = max(res, pf);
    }
    return res;
}

//O(nlogn)
int findPlatform(vector<int> a, vector<int> d, int n){
    int pf=1, res=1, i=0, j=1;
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    while(i<n && j<n){
        if(a[j] <= d[i]){
            pf++;
            j++;
        }
        else if(d[i] < a[j]){
            pf--;
            i++;
        }
        res = max(res, pf);
    }
    return res;
}

// O(n) : Map based
int findPlatform(vector<int> a, vector<int> d, int n){
    int pf=0, res=0;
    multimap<int, char> mp;
	for (int i = 0; i < n; i++) {
	    mp.insert({a[i], 'a'});
	    mp.insert({d[i], 'd'});
	}
    for (auto& it: mp) {
		if (it.second == 'a')
			pf++;
		else
			pf--;
        res = max(res, pf);
    }
    return res;
}

// O(n) : platform time array
int findPlatform(vector<int> a, vector<int> d, int n){
    int pf=1;
    int plat[2361] = {0};
    for(int i=0; i<n; i++){
        plat[a[i]]++;
        plat[d[i]+1]--;
    }
    for(int i=1; i<2361; i++){
        plat[i] += plat[i-1];
        pf = max(pf, plat[i]);
    }
    return pf;
}
