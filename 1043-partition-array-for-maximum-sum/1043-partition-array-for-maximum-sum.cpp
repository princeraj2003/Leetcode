class Solution {
public:
    int solve(int i,vector<int>&arr,int k,vector<int>&dp){
        int n=arr.size();
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int l=0;
        int maxi=INT_MIN;
        int ans=INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            l++;
            maxi=max(maxi,arr[j]);
            int finalans=l*maxi+solve(j+1,arr,k,dp);
            ans=max(ans,finalans);
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,k,dp);
    }
};