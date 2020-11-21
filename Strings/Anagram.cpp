// Same count of distinct characters

bool isAnagram(string c, string d){
    unordered_map<char,int> mp;
    int m = c.size(), n=d.size();
    if(m != n)  return 0;
    for(int i=0; i<n; i++){
        mp[c[i]]++;
        mp[d[i]]--;
    }

    for(auto& it : mp)
        if(it.second != 0)
            return 0;
    
    return 1;
}
