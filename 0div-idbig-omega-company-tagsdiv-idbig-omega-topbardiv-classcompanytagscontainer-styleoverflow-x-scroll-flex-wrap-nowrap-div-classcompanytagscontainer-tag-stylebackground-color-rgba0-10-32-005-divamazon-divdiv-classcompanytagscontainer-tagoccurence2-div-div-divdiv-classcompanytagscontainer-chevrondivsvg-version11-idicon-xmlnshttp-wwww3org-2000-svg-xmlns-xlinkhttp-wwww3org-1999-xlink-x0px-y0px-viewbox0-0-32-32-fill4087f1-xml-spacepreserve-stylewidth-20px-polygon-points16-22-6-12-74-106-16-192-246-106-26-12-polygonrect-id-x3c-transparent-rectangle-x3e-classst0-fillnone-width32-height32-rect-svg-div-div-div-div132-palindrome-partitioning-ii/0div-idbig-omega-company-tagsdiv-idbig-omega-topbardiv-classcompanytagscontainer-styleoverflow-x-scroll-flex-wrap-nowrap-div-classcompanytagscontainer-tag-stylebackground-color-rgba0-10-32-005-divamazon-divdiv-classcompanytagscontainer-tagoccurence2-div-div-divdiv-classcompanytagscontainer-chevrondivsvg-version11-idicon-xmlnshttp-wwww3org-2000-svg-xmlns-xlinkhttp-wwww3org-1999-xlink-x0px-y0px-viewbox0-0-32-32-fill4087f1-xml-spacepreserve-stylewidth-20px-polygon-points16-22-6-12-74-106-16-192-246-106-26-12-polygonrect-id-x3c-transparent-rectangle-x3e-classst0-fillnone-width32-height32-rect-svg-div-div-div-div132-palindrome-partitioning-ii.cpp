class Solution {
public:
bool isPalindrone(string &s,int i,int j){
    while(j>=i){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solve(string &s,int i,vector<int>&dp){
    if(i>=s.size() || isPalindrone(s,i,s.size()))
    return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=i;j<s.size();j++){
        if(isPalindrone(s,i,j)){
            int cost=1+solve(s,j+1,dp);
            ans=min(ans,cost);
        }
    }
    return dp[i]=ans;
}
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return solve(s,0,dp)-1;
    }
};