class Solution {
private:
    bool f(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0) return (nums[0] == target);

        if(dp[index][target] != -1) return dp[index][target];
        bool notTake = f(index-1, target, nums, dp);
        bool take = false;
        if(nums[index] <= target) take = f(index-1, target - nums[index], nums, dp);

        return dp[index][target] = take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        vector<vector<int>> dp(n, vector<int>((sum/2) + 1, -1));
        return f(n-1, sum/2, nums, dp);
    }
};