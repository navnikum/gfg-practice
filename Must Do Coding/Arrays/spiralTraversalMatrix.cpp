vector<int> spirallyTraverse(vector<vector<int> >& m, int row, int col) {
        int l,r,t,b,i,j;
        l=0, r=col-1, t=0, b=row-1;
        vector<int> v;
        int dir = 0;
        while(l<=r && t<=b){
            if(dir==0){
                for(i=l; i<=r; i++)  v.push_back(m[t][i]);
                t++;
            }
            if(dir==1){
                for(j=t; j<=b; j++)  v.push_back(m[j][r]);
                r--;
            }
            if(dir==2){
                for(i=r; i>=l; i--)  v.push_back(m[b][i]);
                b--;
            }
            if(dir==3){
                for(j=b; j>=t; j--)  v.push_back(m[j][l]);
                l++;
            }
            
            dir= (dir+1) % 4;
        }
    return v;
}
