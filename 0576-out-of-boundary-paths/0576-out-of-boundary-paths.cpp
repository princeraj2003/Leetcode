class Solution {
    public:
    int mod=1e9+7;
    int memo[51][51][51];

    int solve(int m, int n, int Maxmove, int i,int j ){
        if(i>=m || i<0 || j>=n ||j<0){
            return 1;
        }
        if(Maxmove<=0){
            return 0;
        }
        if(memo[i][j][Maxmove]!=-1){
            return memo[i][j][Maxmove];
        }
        long res=0;
        res+=solve(m,n,Maxmove-1,i+1,j);
        res+=solve(m,n,Maxmove-1,i-1,j);
        res+=solve(m,n,Maxmove-1,i,j+1);
        res+=solve(m,n,Maxmove-1,i,j-1);
        return  memo[i][j][Maxmove]= res%mod;
    }
    int findPaths(int m, int n, int Maxmove, int startRow, int startColumn) {
        memset(memo,-1,sizeof(memo));
        return solve(m,n,Maxmove,startRow,startColumn)%mod;
    }
};