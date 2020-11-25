bool chck(string s){
  stack<char> s;
    int k = x.length();
    for(int i=0; i<k; i++){
        char ch = x[i], c;
        if(ch == '{' || ch == '(' || ch == '[' || s.empty()){
            s.push(ch);
        }
        else{
            if((s.top() == '{' && ch == '}') ||  (s.top() == '(' && ch == ')') || (s.top() == '[' && ch == ']'))
                s.pop();
            else
                s.push(ch);
        }
    }
    return s.empty();
}
