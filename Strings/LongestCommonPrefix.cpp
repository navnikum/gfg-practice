// character by character O(NM) O(1) 
int findMinLength(vector<string>& s){
    int n=s.size(), res=s[0].size();
    for(int i=1; i<n; i++){
        int p = s[i].size();
        res = min(res, p);
    }
    return res;
}
string longestPrefix(vector<string>& s){
    int n= s.size();
    int minl = findMinLength(s);
    string res;
    char curr;
    for(int i=0; i<minl; i++){
        curr = s[0][i];
        for(int j=1; j<n; j++){
            if(s[j][i] != curr)
                return res;
        }
        res.push_back(curr);
    }
    return res;
}

// Sorting //O(MAX + nlog n)
string longestPrefix(vector<string>& s){
    int n = s.size();
    if(n==0) return "";
    string ans  = "";
    sort(begin(s), end(s));
    string a = s[0];
    string b = s[n-1];
    
    for(int i=0; i<a.size(); i++){
        if(a[i]==b[i])  ans += a[i];
        else    break;
    }
    return ans;
}

// TRIE
struct TrieNode {
    int freq;
    TrieNode* child[26];
};

TrieNode* newTrieNode(){
    TrieNode* newNode = new TrieNode();
    newNode->freq = 1;
    for(int i=0; i<26; i++)
        newNode->child[i] = NULL;
    return newNode;
}

void insert(string w, TrieNode* root){
    int l = w.length();
    TrieNode* runner = root;
    for(int i=0; i<l; i++){
        int lvl = w[i] - 'a';
        if(runner->child[lvl] == NULL)
            runner->child[lvl] = newTrieNode();
        else
            (runner->child[lvl]->freq)++;
        runner = runner->child[lvl];
    }
}

string lcp(vector<string>& v){
    int n = v.size();
    TrieNode* root = newTrieNode();
    root->freq = 0;
    for(int i=0; i<n; i++)  insert(v[i], root);
    
    string ans = "";
    TrieNode* runner = root;
    bool found = 1;
    while(found){
        found = 0;
        for(int i=0; i<26; i++){
            if(runner->child[i] != NULL){
                if(runner->child[i]->freq == n){
                    ans += char(i+'a');
                    found = 1;
                    runner = runner->child[i];
                    break;
                }
            }
        }
    }
    return ans;
}
