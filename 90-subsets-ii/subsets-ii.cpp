class Solution {
private:
    void backtrack(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& ans) {
        if(index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        output.push_back(nums[index]);
        backtrack(nums, index+1, output, ans);
        output.pop_back();
        int idx = index+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        backtrack(nums, idx, output, ans);


    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(nums, 0, output, ans);
        return ans;
    }
};