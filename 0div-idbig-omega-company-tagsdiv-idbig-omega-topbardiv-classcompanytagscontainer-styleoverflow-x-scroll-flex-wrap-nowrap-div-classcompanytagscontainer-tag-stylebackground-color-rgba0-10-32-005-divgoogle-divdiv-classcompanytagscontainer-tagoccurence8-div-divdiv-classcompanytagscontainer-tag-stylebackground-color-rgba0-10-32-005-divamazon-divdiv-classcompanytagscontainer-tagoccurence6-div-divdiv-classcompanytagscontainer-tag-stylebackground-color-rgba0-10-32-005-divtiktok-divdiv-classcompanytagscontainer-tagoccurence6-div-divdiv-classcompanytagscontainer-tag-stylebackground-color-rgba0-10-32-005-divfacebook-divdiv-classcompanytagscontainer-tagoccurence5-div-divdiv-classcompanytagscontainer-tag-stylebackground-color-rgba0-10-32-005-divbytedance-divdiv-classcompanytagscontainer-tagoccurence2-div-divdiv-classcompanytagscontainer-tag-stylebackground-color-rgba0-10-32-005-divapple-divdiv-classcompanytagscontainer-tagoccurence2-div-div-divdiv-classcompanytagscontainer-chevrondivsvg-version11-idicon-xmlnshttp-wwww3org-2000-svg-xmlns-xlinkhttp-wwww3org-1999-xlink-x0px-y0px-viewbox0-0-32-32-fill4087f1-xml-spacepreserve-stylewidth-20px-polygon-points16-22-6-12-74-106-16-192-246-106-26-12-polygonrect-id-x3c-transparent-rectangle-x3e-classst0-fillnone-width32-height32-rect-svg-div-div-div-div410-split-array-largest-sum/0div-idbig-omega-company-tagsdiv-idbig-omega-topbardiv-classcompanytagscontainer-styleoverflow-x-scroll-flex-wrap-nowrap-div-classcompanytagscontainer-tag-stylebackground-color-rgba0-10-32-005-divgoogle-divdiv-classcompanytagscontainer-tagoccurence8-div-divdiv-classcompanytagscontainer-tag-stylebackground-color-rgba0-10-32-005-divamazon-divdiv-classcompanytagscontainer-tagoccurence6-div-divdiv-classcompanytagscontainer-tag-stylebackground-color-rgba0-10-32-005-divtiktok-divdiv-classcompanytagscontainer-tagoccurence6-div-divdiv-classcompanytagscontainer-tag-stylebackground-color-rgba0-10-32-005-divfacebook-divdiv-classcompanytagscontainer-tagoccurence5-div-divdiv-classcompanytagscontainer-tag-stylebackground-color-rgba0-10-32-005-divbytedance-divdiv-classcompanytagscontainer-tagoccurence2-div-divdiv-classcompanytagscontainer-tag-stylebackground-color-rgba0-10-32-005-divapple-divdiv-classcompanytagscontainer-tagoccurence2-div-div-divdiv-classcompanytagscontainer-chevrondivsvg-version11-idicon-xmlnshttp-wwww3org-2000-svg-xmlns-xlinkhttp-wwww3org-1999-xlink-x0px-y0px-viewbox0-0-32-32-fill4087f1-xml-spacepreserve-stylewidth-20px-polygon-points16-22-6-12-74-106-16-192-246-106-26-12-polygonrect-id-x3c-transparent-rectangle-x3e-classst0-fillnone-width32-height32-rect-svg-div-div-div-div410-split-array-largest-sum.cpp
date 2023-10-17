class Solution {
public:
    bool isPossible(vector<int> arr,int k,int mid){
        int count=1;
        int arrsum=0;
        for(int i=0;i<arr.size();i++){
            if(arrsum+arr[i]<=mid){
                arrsum+=arr[i];
            }
            else{
                count++;
                if(count>k || arr[i]>mid){
                    return false;
                }
                arrsum=arr[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        int mid=-1;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            end+=nums[i];
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};