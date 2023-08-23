class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(candidates, 0, target, output, ans);
        return ans;
    }

    void backtrack(vector<int>& candidates, int index, int target, vector<int>& output, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            output.push_back(candidates[i]);
            backtrack(candidates, i+1, target-candidates[i], output, ans);
            output.pop_back();
        }
    }
};