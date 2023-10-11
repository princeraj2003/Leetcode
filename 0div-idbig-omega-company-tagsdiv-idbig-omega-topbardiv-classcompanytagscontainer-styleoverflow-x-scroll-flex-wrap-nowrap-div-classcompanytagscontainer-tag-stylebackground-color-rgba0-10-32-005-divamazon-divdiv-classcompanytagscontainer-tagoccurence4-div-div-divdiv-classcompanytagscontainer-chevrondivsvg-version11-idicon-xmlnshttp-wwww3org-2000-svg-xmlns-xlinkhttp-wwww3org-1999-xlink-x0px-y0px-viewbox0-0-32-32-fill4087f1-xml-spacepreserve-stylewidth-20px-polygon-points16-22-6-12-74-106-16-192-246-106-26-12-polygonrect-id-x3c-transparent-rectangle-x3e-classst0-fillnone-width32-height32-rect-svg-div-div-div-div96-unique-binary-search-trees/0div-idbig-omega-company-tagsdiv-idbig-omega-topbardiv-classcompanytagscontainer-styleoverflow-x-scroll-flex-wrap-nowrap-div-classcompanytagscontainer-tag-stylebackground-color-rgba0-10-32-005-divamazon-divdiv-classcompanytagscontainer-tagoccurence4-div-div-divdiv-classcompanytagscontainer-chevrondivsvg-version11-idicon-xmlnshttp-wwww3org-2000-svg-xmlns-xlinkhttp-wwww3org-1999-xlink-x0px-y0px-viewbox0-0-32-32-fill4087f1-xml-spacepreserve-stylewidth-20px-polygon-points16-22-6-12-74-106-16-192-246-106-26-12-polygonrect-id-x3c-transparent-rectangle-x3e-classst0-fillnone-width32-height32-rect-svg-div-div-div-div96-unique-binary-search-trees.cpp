class Solution {
public:
int dp[20][20];
int solve(int i, int j){
    if(i>=j)return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    for(int k=i;k<=j;k++)
        ans+=solve(i,k-1)*solve(k+1,j);
        return dp[i][j]=ans;
    
}
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};