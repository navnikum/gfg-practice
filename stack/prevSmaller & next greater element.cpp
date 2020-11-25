vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> s;
    for(int i=0; i<n; i++){
        while(!s.empty() && s.top() >= A[i])    s.pop();
        if(s.empty())   res[i] = -1;
        else    res[i] = s.top();
        s.push(A[i]);
    }
    return res;
}

vector<int> Solution::nxtGreater(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> s;
    for(int i= n-1; i>=0; i++){
        while(!s.empty() && s.top() <= A[i])    s.pop();
        if(s.empty())   res[i] = -1;
        else    res[i] = s.top();
        s.push(A[i]);
    }
    return res;
}
