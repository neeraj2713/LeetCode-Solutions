class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& ans)
    {
        ans.push_back(output);

        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            output.push_back(nums[i]);
            backtrack(nums, i+1, output, ans);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(nums, 0, output, ans);
        return ans;
    }
};