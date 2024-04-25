class Solution {
public:
    int solve(int index,string &s,int prev,int k,vector<vector<int>>&dp){
        if(index==-1){
            return 0;
        }
        if(dp[index][prev]!=-1){
            return dp[index][prev];
        }
        int take=0;
        int ch=s[index]-'a'+1;
        if(prev==0 or abs(ch-prev)<=k){
            take=solve(index-1,s,ch,k,dp)+1;
        }
        int nottake=solve(index-1,s,prev,k,dp);
        return dp[index][prev]=max(take,nottake);
    }
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(27,-1));
       return  solve(n-1,s,0,k,dp);
    }
};