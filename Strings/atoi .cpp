// O(n)
int atoi(string S) {
    int n = S.size(), res = 0;
    bool f=0;
    int i=0;
    if(S[0] == '-') f=1, i++;
    else if(S[0] == '+')    i++;
    while(i < n){
        if(S[i]>='0' && S[i]<='9')
            res = res*10 + S[i]-'0';
        else 
            return -1;
        if(res > INT_MAX)
            return f==1 ? INT_MIN:INT_MAX;
        i++;
    }
    if(f)    return -1*res;
    else    return res;
}
