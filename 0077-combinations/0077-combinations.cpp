class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start,int &n,int k,vector<int>&t){
        if(k==0){
            ans.push_back(t);
            return;
        }
        

       for(int i=start;i<=n;i++){
           t.push_back(i);
           solve(i+1,n,k-1,t);
           t.pop_back();

       }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>t;
        solve(1,n,k,t);
        return ans;
    }
};