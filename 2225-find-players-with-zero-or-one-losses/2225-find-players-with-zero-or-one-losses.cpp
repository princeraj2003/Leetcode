class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>win;
        unordered_map<int,int>lost;
        for(int i=0;i<matches.size();i++){
            win[matches[i][0]]++;
            lost[matches[i][1]]++;
        }
        vector<int>onelost;
        auto it=lost.begin();
        while(it!=lost.end()){
            if(it->second==1)onelost.push_back(it->first);
            it++;
        }
        vector<int>zerolost;
        auto it2=win.begin();
        while(it2!=win.end()){
            if(it2->second>=1 && lost[it2->first]==0)zerolost.push_back(it2->first);
            it2++;
        }
        sort(onelost.begin(),onelost.end());
        sort(zerolost.begin(),zerolost.end());
        vector<vector<int>>ans;
        ans.push_back(zerolost);
        ans.push_back(onelost);
        return ans;

    }
};