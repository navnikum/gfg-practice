https://practice.geeksforgeeks.org/problems/equilibrium-point/0

// rightsum = arraysum - leftsum;


#include <bits/stdc++.h>
using namespace std;

void equib(vector<int> a, int n){
    int leftsum = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    int i;
    for(i = 0; i < n; i++){
        sum -= a[i];
        if(sum == leftsum){
            cout<<i+1<<endl;
            break;
        }
        leftsum += a[i];
    }
    if(i == n)
        cout<<-1<<endl;
}

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a;
        for(int i = 0; i < n; i++){
            int p ;
            cin>>p;
            a.push_back(p);
        }
        equib(a, n);
    }
	return 0;
}
