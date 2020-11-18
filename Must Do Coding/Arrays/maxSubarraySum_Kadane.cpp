int maxSubarraySum(vector<int>& v, int n){
    int cursum=0, farsum=INT_MIN; 
    int s=0, start=0, end=0;
    for(int i=0; i < n; i++){
        /*cursum = max(0, cursum+v[i]);
        farsum = max(cursum, farsum);*/
        cursum += v[i];
        if(cursum > farsum){
            farsum = cursum;
            start = s;
            end = i;
        }
        if(cursum < 0){
            cursum = 0;
            s = i+1;
        }
    }
    return farsum;
}
