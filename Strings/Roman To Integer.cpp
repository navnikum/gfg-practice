// Input : MCMIV -> Output : 1909

int value(char r);
int romanToDecimal(string& str){
    int k=str.size(), n = 0,a,b;
    for(int i=0; i<k-1; i++){
        a = value(str[i]);
        b = value(str[i+1]);
        if(a >= b)
            n += a;
        else
            n += (b-a), i++;
    }
    n += value(str[k-1]);
    return n;
}

int value(char r){
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

int main() {
	int t;  cin>>t;
	while(t--){
	    string s;   cin>>s;
	    cout<<romanToDecimal(s)<<endl;
	}
	return 0;
}
