// O(n^2) O(1)
bool isPalli(string s){
    int l = 0, r = s.size()-1;
    while(l < r){
        if(s[l++] != s[r--])
            return 0;
    }
    return 1;
}

int palli(string s){
    /*int cnt=0, f=0;
    while(s.size() > 0){
        if(isPalli(s)){
            f = 1;
            break;
        }
        else{
            cnt++;
            s.erase(s.begin() + s.size() - 1);
        }
    }
    if(f)   return cnt;*/
    // Recursive
    if (isPalli(s))
        return 0;
        
    s.erase(s.begin() + s.size() - 1);
 
    return 1 + palli(s);
}

// O(n) O(n)
// KMP preprocessing
int prefix_function(string str) {
    int M = str.size();
    vector<int> lps(M);
	lps[0] = 0; 
	int i = 1, len = 0;  
	while (i < M){ 
		if (str[i] == str[len]) { 
			len++; 
			lps[i++] = len; 
		} 
		else{  
			if (len != 0)  
				len = lps[len-1]; 
			else
				lps[i++] = 0; 
		} 
	}
	return lps[M-1];
}
int palli(string str){
    int k = str.size();
    string revStr = str; reverse(revStr.begin(), revStr.end()); 
	string concat = str + "$" + revStr;
	int l = prefix_function(concat);
	return k-l;
}
