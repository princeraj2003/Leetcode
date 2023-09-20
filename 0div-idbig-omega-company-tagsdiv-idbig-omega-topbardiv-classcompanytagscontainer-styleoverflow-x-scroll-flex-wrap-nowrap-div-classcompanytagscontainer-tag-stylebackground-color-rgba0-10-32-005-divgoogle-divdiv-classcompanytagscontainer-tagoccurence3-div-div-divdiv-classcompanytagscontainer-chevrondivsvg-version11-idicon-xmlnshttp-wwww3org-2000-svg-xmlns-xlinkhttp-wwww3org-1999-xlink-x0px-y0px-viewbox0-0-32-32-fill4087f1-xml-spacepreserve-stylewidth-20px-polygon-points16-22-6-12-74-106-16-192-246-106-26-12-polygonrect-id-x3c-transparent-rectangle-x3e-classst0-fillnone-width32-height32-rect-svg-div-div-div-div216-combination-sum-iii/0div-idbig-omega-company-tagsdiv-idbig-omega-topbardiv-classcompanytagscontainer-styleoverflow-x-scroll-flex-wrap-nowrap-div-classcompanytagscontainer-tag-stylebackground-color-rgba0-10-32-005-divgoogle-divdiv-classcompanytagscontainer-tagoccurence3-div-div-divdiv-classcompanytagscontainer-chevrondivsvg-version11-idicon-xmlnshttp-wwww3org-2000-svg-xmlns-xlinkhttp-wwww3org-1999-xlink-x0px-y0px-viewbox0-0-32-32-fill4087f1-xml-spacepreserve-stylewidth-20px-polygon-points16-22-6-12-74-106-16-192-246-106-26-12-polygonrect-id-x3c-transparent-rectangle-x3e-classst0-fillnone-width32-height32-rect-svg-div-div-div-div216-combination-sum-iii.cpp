class Solution {
private:
    void getCombinations(int idx, int k, int target, vector<vector<int>>& combinations, vector<int>& comb) {
        if(target == 0 && comb.size() == k) {
            combinations.push_back(comb);
            return;
        }
        
        if(comb.size() < k) {
             for(int i = idx; i<=9; i++) {
                 if(target - i < 0) break;
                 comb.push_back(i);
                 getCombinations(i+1, k, target - i, combinations, comb);
                 comb.pop_back();
             }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> comb;
        
        getCombinations(1, k, n, combinations, comb);
        
        return combinations;
    }
};