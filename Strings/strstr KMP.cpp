// O(n)
int strstr(string txt, string pat){ 
	int n = txt.size(), m = pat.size();
	int i, t=0;
	for(i=0; i<n; i++){
	    if(t == m)  break;
	    if(txt[i] == pat[t])    t++;
	    else    t=0;
	}
	return (t < m)? -1: (i-t);
} 

// KMP O(n)
vector<int> prefix_function(string str) {
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
	return lps;
}

int strstr(string txt, string pat){ 
	int M = pat.size(); 
	int N = txt.size(); 
  vector<int> lps = prefix_function(pat); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			return (i - j); 
			//j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i++; 
		} 
	} 
	return -1;
} 
