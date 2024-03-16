class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n=nums.size();
       int result=0;
       int currsum=0;
       unordered_map<int,int>mp;
       mp[0]=-1;
       for(int i=0;i<n;i++){
        currsum+=(nums[i]==1)?1:-1;
        if(mp.find(currsum)!=mp.end()){
            result=max(result,i-mp[currsum]);
        }else{
            mp[currsum]=i;
        }
       }
       return result;
    }
};