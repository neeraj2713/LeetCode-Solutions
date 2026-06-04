class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        unordered_set<int> st;
        int a, b;
        int sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(st.find(grid[i][j]) != st.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                } else {
                    st.insert(grid[i][j]);
                }
                sum += grid[i][j];

            }
        }

        int total_sum = (n*n)*(n*n +1)/2;
        b = total_sum + a - sum;
        ans.push_back(b);

        return ans;
    }
};