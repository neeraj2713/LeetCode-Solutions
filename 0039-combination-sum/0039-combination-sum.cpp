class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(candidates, 0, target, output, ans);
        return ans;
    }

    void backtrack(vector<int>& candidates, int i, int target, vector<int>& output, vector<vector<int>>& ans){
        if(i >= candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }

        if(candidates[i] <= target){
            output.push_back(candidates[i]);
            backtrack(candidates, i, target-candidates[i], output, ans);
            output.pop_back();
        }

        backtrack(candidates, i+1, target, output, ans);
    }
};