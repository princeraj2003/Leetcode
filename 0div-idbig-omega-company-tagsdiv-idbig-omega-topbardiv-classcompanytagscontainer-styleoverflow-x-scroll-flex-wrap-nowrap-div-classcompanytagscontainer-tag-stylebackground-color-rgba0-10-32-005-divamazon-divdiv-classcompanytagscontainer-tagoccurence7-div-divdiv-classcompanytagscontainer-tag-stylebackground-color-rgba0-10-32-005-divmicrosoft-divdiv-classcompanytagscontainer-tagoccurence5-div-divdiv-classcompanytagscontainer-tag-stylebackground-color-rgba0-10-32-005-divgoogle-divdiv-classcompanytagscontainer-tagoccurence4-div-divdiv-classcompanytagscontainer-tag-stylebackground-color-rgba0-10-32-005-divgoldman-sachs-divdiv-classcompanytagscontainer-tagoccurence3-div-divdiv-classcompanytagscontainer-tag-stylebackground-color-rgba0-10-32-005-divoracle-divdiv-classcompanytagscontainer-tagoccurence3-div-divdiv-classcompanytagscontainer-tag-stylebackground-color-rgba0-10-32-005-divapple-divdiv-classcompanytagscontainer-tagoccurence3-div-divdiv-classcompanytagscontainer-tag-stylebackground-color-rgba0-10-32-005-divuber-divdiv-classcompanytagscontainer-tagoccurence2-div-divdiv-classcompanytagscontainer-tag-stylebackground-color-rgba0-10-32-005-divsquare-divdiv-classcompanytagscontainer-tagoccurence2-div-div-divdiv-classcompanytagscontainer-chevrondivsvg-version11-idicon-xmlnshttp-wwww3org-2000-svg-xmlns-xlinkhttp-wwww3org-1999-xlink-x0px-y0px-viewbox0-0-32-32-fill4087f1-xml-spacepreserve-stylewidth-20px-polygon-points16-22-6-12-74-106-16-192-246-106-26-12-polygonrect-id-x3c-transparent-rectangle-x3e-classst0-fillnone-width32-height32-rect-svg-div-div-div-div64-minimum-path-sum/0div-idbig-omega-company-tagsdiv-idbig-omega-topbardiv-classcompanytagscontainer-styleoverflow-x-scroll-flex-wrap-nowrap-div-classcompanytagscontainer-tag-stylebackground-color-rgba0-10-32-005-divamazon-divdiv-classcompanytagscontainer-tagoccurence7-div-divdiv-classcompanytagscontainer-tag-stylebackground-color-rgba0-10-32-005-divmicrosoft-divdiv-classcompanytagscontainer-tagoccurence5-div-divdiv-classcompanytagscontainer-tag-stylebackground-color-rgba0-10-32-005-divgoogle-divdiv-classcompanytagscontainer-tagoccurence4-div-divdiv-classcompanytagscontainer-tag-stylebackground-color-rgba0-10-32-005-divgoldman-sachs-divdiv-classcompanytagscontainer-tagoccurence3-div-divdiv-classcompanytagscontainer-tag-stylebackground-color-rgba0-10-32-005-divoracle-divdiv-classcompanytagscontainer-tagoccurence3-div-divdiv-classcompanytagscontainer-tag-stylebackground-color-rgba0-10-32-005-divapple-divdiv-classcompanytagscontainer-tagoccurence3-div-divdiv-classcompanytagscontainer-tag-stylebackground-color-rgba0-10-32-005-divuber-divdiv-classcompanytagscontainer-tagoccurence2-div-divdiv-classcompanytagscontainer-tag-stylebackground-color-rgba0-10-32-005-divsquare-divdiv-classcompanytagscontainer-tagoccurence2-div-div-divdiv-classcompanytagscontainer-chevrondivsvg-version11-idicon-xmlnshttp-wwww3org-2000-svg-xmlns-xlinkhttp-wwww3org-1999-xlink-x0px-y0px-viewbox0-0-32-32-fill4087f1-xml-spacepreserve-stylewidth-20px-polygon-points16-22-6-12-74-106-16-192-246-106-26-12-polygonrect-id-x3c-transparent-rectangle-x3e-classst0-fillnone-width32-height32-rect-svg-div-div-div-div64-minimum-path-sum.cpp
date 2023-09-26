class Solution
{
private:
    int m, n;

    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return INT_MAX;
        if (i == 0 && j == 0)
            return dp[i][j] = grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        // Go Up
        int up = helper(i - 1, j, grid, dp);

        // Go Left
        int left = helper(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left) + grid[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        helper(m - 1, n - 1, grid, dp);

        return dp[m - 1][n - 1];
    }
};