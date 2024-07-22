class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, i-1, j, n, m)
                 + dfs(grid, i, j-1, n, m)
                 + dfs(grid, i+1, j, n, m)
                 + dfs(grid, i, j+1, n, m);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    result = max(result, dfs(grid, i, j, n, m));
                }
            }
        }

        return result;
    }
};