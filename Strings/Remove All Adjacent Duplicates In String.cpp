// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Stack based
string removeDuplicates(string S) {
    string res = "";
    for (auto& c : S)
        if (res.size() && c == res.back())
            res.pop_back();
        else
            res.push_back(c);
    return res;
}

string removeDuplicates(string a) {
    stack<char> st;
	  string ans="";
    for(auto c:a) {
      if(!st.empty() && st.top() == c) st.pop();
      else st.push(c);
    }
    while(!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Recursive
string removeDuplicates(string S) {
    for (auto i = 1; i < S.size(); ++i)
        if (S[i-1] == S[i])
            return removeDuplicates(S.substr(0, i-1)+S.substr(i+1));
    return S;
}



// Input : aaaaaaaaaaaaa -> Output : _
void removeDuplicates(string& str) {
	char prev = str[0];	// stores previous valid character
	int k = 0;  // k maintains the index of last filled location in the result
	int i = 1;  // start from second character

	while (i < str.length()){
		// if the current character is not same as the previous character
		if (prev != str[i]){
			str[++k] = str[i++];	// update result
			prev = str[k];  		// update prev
		}
		else{
			// remove adjacent duplicates
			while (prev == str[i])
				i++;

			prev = str[--k];		// update prev
		}
	}

	// delete str[k+1, n) as result lies in str[0..k]
	str.erase(k + 1);
}
