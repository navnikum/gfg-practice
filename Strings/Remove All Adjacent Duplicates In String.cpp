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
