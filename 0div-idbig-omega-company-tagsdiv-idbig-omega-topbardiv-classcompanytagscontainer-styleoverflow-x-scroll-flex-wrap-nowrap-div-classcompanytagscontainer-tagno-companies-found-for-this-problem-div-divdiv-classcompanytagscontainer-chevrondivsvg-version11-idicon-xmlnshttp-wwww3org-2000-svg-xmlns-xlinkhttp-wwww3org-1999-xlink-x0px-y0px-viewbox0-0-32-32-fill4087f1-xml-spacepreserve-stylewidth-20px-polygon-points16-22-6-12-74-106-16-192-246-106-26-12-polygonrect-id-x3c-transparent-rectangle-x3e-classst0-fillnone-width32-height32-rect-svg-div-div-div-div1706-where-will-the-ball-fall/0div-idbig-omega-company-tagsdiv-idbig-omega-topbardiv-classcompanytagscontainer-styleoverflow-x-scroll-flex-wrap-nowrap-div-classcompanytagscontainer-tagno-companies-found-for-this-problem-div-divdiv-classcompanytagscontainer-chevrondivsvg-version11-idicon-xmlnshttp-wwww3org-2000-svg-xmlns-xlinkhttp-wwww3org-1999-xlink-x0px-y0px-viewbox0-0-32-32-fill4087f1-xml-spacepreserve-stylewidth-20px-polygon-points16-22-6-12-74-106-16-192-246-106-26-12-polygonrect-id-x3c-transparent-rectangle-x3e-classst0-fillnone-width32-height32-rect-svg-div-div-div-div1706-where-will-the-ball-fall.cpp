class Solution {
public:
    int depthTrav(int col, vector<vector<int>>& grid){
      for(int i = 0;i<grid.size(); i++){
        if(grid[i][col] == 1){
            if(col+1 == grid[0].size() || grid[i][col+1] != 1){
                return -1;
            }
            else{
              col++;
            }
        }
        else{
            if(col-1<0 || grid[i][col-1] != -1){
                return -1;
            }
            else{
              col--;
            }
        }
      }
      return col;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
      vector<int> ans(grid[0].size());
        for(int i = 0; i<grid[0].size(); i++){
          ans[i] = depthTrav(i, grid);  
        }
       return ans; 
    }
};