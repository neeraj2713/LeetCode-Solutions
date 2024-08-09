class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int x, int y){
        unordered_set<int> nums;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                int num = grid[i][j];
                if(num < 1 || num > 9 || nums.count(num)){
                    return false;
                }
                nums.insert(num);
            }
        }

        // Sum of the first row
        int sum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        
        // Check rows
        if (grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2] != sum) return false;
        if (grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] != sum) return false;
        
        if (grid[x][y] + grid[x + 1][y] + grid[x + 2][y] != sum) return false;
        if (grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1] != sum) return false;
        if (grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2] != sum) return false;
        
        if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != sum) return false;
        if (grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y] != sum) return false;
        
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(grid[i+1][j+1] == 5 && isMagicSquare(grid, i, j)){
                    count++;
                }
            }
        }

        return count;
    }
};