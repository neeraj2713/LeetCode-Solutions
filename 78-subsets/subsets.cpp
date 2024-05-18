class Solution {
private:
    void solver(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        output.push_back(nums[index]);
        solver(nums, index+1, output, ans);
        output.pop_back();
        solver(nums, index+1, output, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solver(nums, index, output, ans);
        return ans;
    }
};