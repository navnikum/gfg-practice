// Find number of pairs (x, y) in an array such that x^y > y^x

// O(m*n) O(1)
int countPairsBruteForce(vector<int> X, vector<int> Y, int m, int n){
    int cnt=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(pow(X[i],Y[j]) > pow(Y[j],X[i]))
                cnt++;
    return cnt;
}

// x smaller than y means x^y is greater than y^x
// O(nlogm + mlogn) O(1)
int count(int x, vector<int>& Y, int n, vector<int>& cntY){
    if(x == 0)  return 0;
    if(x == 1)  return cntY[0];
    int ans = Y.end() - upper_bound(Y.begin(), Y.end(), x);
    ans += (cntY[0]+cntY[1]);
    if(x == 2)  ans-=(cntY[2]+cntY[3]);
    if(x == 3)  ans +=cntY[2];
    return ans;
}
int countPairs(vector<int>& X, vector<int>& Y, int m, int n){
    vector<int> cntY(5,0);
    for(int i=0; i<n; i++)
        if(Y[i] < 5)
            cntY[Y[i]]++;
    
    sort(Y.begin(), Y.end());
    int cnt = 0;
    for(int i=0; i<m; i++)
        cnt += count(X[i], Y, n, cntY);
    return cnt;
}
