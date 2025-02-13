class Solution {
private:
    void backtrack(vector<int>& nums, int idx, vector<int>& output, vector<vector<int>>& ans){
        if(idx >= nums.size()){
            ans.push_back(output);
            return;
        }

        output.push_back(nums[idx]);
        backtrack(nums, idx+1, output, ans);
        output.pop_back();
        backtrack(nums, idx+1, output, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(nums, 0, output, ans);
        return ans;
    }
};