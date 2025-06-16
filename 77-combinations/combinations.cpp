class Solution {
private:
    void backtrack(int n, int k, int idx, vector<int>& output, vector<vector<int>>& ans){
        if(output.size() == k){
            ans.push_back(output);
            return;
        }

        for(int i=idx;i<=n;i++){
            output.push_back(i);
            backtrack(n, k, i+1, output, ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(n, k, 1, output, ans);
        return ans;
    }
};