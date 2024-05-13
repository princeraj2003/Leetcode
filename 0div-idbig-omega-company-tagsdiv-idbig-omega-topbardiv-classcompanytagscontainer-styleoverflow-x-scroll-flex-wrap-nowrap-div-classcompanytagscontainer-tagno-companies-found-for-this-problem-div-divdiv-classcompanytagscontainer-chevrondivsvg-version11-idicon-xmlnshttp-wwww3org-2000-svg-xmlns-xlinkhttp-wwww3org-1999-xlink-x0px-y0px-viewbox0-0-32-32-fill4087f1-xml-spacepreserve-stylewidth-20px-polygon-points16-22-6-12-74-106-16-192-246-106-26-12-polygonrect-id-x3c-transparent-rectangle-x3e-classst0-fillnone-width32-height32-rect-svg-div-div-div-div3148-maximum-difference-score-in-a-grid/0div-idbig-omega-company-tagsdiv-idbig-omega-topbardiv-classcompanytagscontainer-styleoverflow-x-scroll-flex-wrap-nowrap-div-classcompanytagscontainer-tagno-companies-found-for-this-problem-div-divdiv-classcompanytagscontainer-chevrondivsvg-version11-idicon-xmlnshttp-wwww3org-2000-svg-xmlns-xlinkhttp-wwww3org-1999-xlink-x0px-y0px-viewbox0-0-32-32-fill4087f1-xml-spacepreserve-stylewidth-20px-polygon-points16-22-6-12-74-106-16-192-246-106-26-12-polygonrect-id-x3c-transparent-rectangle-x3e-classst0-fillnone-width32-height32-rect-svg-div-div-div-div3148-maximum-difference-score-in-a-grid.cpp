class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i>=grid.size() || j>=grid[0].size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pick1=INT_MIN,pick2=INT_MIN;
        if(i+1<grid.size())pick1=grid[i+1][j]-grid[i][j]+solve(i+1,j,grid,dp);
        if(j+1<grid[0].size())pick2=grid[i][j+1]-grid[i][j]+solve(i,j+1,grid,dp);
        dp[i][j]=max(0,max(pick1,pick2));
        return dp[i][j];
    }
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=INT_MIN;
        int maxi1=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,solve(i,j,grid,dp));
                if(i+1<n)maxi1=max(maxi1,grid[i+1][j]-grid[i][j]);
                if(j+1<m)maxi1=max(maxi1,grid[i][j+1]-grid[i][j]);
            }
        }
        if(maxi==0)return maxi1;
    return maxi;

    }
};