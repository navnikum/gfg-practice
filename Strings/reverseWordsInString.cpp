string reverseWords(string s) {
    int i, k = s.size();
    string w="", st="";
    for(i=0; i<k; i++){
        if(s[i]!='.')
            w = w + s[i];
        else{
            if(st == "")    st = w;
            else    st = w+'.'+st;
            w = "";
        }
    }
    if(st == "")    st = w;
    else    st = w+'.'+st;
    return st;
} 

// Input:S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
