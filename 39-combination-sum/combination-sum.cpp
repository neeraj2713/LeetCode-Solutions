class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int idx,vector<int>& output,vector<vector<int>>& ans) {
        if(idx == candidates.size() || target < 0){
            return;
        }

        if(target == 0) {
            ans.push_back({output});
            return;
        }

        output.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, output, ans);
        output.pop_back();
        // Exclude current candidate
        backtrack(candidates, target, idx + 1, output, ans);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(candidates, target, 0, output, ans);
        return ans;
    }
};