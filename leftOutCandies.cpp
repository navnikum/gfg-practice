https://practice.geeksforgeeks.org/problems/left-out-candies/0

#include <bits/stdc++.h>
using namespace std;

void leftCandies(int n, int m){
    int loop = n * (n+1)/2;
    int remain = m % loop;
    for(int i = 0; i < n; i++){
        remain -= i+1;
        if(remain < 0){
            cout<< remain + i+1 <<endl;
            break;
        }
    }
}

int main() {
    int t, n, m;
    cin>>t;
    while(t--){
        // n : kids ; m : candies
        cin>>n>>m;
        leftCandies(n, m);
    }
	return 0;
}
