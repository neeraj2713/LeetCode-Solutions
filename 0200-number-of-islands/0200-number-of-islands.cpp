class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>> &visi,vector<vector<char>>& grid)
    {
        int m = grid.size(),n = grid[0].size(),nr,nc;
        int row[] = {0,-1,0,1};
        int col[] = {-1,0,+1,0};
        visi[sr][sc] = 1;
        for(int i = 0;i<4;i++)
        {
            nr = sr+row[i];
            nc = sc+col[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == '1' && visi[nr][nc] == 0 )
            dfs(nr,nc,visi,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>visi(m,vector<int>(n,0));
        int ans = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == '1' && visi[i][j] == 0)
                {
                    dfs(i,j,visi,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};





