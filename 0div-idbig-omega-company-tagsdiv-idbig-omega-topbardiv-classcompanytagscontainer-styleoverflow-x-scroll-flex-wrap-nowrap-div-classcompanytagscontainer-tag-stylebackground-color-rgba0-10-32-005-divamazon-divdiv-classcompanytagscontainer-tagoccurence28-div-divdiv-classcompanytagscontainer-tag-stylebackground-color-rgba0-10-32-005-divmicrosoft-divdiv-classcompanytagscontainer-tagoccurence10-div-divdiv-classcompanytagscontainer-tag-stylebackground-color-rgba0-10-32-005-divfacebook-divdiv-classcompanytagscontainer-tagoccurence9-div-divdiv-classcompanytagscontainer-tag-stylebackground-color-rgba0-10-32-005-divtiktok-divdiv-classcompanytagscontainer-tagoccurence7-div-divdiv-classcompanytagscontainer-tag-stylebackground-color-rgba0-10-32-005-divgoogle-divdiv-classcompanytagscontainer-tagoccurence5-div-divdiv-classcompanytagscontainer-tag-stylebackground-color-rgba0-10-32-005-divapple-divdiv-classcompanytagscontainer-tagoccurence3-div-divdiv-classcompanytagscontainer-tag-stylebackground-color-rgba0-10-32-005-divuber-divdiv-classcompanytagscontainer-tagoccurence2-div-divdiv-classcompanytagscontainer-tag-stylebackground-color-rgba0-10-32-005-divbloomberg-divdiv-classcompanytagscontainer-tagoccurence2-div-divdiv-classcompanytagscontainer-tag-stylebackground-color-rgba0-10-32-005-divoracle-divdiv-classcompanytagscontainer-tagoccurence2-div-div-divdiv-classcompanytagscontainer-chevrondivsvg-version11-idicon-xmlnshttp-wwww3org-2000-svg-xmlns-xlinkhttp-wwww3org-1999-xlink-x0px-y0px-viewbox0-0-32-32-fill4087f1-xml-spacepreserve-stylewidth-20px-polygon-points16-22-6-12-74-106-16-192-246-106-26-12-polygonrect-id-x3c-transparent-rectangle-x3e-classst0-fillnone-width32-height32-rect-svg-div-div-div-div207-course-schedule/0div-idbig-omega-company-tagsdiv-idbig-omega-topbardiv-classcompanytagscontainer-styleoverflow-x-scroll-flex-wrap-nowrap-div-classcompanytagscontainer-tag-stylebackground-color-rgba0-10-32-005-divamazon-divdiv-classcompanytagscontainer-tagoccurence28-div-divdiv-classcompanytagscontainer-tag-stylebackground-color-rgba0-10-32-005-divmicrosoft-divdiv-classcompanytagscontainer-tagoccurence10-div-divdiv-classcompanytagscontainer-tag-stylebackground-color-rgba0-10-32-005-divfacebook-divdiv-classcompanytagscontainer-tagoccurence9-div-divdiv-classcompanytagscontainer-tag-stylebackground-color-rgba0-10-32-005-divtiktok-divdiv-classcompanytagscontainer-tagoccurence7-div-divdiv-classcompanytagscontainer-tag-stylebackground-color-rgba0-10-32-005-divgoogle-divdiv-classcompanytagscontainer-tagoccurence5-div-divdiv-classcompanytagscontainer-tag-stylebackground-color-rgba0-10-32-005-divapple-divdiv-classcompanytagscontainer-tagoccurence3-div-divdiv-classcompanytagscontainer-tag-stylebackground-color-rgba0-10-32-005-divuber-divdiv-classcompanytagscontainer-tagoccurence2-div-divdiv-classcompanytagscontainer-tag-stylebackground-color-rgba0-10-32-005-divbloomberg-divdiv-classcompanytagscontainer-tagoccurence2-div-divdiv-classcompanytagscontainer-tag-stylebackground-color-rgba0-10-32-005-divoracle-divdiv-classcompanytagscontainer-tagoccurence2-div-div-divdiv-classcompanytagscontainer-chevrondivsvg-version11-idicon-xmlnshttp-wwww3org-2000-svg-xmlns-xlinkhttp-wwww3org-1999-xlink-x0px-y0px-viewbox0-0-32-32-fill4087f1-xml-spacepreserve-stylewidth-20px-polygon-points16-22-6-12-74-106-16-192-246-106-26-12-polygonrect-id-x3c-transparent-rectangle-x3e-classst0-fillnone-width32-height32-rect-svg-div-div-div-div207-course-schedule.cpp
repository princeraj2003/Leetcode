class Solution {
public:
  bool dfs(int index,vector<vector<int>> &adj,vector<int> &vis,vector<int> &temp){
      vis[index] = 1;
      temp[index] = 1;
    for(int i = 0 ; i<adj[index].size();i++){
        int node = adj[index][i];
        if(vis[node] == -1 && dfs(node,adj,vis,temp) == true) return true;
        else if( temp[node] == 1)  return true;
        }
    
    temp[index] = -1;

    return false;
  }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses,-1);
        vector<int> temp(numCourses,-1);
        for(int i = 0;i<numCourses;i++){
        if( vis[i] == -1){
         if (dfs(i,adj,vis,temp) == true)
         return false;}

        }
        return true;
    }
};