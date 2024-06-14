class Solution {
private:
    void backtrack(vector<int>& candidates, int index, vector<int>& output, vector<vector<int>>& ans, int target){
        if(index >= candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }

        if(candidates[index] <= target){
            output.push_back(candidates[index]);
            backtrack(candidates, index, output, ans, target - candidates[index]);
            output.pop_back();
        }

        backtrack(candidates, index+1, output, ans, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(candidates, 0, output, ans, target);
        return ans;
    }
};