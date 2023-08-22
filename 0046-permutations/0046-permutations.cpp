class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<vector<int>> &ans){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=0;j<=i;j++){
            swap(nums[i], nums[j]);
            backtrack(nums, i+1, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;

    }
};