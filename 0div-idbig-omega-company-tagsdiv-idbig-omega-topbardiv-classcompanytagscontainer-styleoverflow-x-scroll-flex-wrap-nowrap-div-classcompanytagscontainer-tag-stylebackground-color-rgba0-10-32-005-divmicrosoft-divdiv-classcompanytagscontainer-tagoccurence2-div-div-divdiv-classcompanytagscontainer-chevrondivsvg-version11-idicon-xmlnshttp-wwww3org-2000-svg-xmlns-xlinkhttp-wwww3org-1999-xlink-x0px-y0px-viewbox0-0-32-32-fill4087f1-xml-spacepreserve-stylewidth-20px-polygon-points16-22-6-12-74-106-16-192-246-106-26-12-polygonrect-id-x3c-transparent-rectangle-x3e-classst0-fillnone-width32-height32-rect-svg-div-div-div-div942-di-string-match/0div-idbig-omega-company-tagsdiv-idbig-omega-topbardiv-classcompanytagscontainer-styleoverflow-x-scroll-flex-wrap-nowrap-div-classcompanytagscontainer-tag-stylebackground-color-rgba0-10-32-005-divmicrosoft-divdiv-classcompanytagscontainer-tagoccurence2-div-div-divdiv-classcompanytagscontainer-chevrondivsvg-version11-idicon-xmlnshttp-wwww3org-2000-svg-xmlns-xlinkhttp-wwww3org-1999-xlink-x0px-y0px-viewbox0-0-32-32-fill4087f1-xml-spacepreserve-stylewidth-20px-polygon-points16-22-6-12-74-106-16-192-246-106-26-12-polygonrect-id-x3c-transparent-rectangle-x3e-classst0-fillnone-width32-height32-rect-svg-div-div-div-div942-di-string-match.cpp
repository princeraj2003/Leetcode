class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0;
        int j=s.length();
        vector<int>ans;
        for(auto it:s){
            if(it=='I'){
ans.push_back(i);
i++;
            }else{
                ans.push_back(j);
                j--;
            }
        }
        ans.push_back(i);
        return ans;
    }
};