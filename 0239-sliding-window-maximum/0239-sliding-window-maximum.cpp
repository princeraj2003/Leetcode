class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ans;
        int begin=0,end=0;
        while(end<k){
            s.insert(nums[end]);
            end++;
        }
        end--;
        while(end<nums.size()){
            ans.push_back(*(--s.end()));
            s.erase(s.find(nums[begin]));
            begin++;
            end++;
            if(end<nums.size()) {s.insert(nums[end]);}
        }
        return ans;
    }
};