class Solution{
    static int myCompare(string a, string b){
        return (a+b).compare(b+a) > 0 ? 1:0;
    }
public:
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), myCompare);
	    string s;
	    for(int i=0; i < arr.size(); i++)
	        s+=arr[i];
	    return s;
	}
};
