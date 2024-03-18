class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double currsum=0,maxsum=0;
        for(int i=0;i<k;i++){
            currsum+=nums[i];

        }
        maxsum=currsum;
        for(int i=k;i<n;i++){
            currsum+=nums[i]-nums[i-k];
            maxsum=max(currsum,maxsum);
        }
        return maxsum/k;
    }
};