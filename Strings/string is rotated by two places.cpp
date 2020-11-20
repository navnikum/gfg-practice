bool isRotated(string str1, string str2){
    int n = str1.size(), m = str2.size();
    if(m != n)  return 0;
    if(n == 0)    return 0;
    if(n == 1){  
        if(str1 == str2)
            return 1;
        else return 0;
    }
    string a = str1.substr(2) + str1.substr(0, 2);
    string b = str1.substr(n-2) + str1.substr(0, n-2);
    if(str2.compare(a) == 0 || str2.compare(b) == 0)
        return 1;
    return 0;
}
