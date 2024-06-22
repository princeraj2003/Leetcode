class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int oddcnt=0;
        unordered_map<int,int>mp;
        mp[oddcnt]=1;
        for(int i=0;i<n;i++){
            oddcnt+=(nums[i]%2);
            if(mp.count(oddcnt-k)){
                ans+=mp[oddcnt-k];
            }
            mp[oddcnt]++;
        }
        return ans;
    }
};