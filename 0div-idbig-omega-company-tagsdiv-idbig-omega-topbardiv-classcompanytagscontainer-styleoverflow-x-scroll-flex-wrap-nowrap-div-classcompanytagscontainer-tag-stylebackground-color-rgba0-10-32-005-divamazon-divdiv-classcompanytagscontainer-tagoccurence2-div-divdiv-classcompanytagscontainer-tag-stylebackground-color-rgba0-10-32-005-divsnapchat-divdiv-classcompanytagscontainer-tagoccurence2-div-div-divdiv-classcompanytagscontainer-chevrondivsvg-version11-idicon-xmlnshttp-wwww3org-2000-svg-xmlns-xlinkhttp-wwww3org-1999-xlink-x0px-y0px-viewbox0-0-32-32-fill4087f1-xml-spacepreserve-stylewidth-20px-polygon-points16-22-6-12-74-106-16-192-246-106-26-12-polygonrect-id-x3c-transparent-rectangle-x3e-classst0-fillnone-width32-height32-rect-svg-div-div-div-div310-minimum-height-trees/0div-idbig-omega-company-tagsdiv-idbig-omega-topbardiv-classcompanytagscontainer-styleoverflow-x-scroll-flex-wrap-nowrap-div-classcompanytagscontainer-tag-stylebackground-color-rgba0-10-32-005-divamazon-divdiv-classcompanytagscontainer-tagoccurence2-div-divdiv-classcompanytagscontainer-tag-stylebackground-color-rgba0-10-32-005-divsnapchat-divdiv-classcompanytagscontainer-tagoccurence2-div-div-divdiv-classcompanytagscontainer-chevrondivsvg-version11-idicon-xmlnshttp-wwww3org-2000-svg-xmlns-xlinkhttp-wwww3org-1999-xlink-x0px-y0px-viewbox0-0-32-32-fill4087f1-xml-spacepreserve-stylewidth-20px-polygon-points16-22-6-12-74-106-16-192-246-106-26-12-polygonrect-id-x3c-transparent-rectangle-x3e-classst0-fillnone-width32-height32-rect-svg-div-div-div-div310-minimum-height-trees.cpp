class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<vector<int>>adj(n);
        vector<int>degree(n);
        for(vector<int>&it:edges){
            int from=it[0],to=it[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
            degree[from]++;
            degree[to]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
            if(degree[i]==1)q.push(i);
            while(!q.empty()){
                int size=q.size();
                if(size==n)break;
                while(size--){
                    int curr=q.front();
                    q.pop();
                    n--;
                    for(int next:adj[curr]){
                        if(--degree[next]==1)q.push(next);
                    }
                }
            }
            vector<int>result;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                result.push_back(curr);
            }
            return result;
        
        
    }
};