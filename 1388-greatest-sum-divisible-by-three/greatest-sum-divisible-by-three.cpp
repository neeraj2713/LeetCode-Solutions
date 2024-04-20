class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp{0, 0, 0};
        for(int i=0;i<nums.size();i++){
            vector<int> temp;
            temp = dp;
            for(auto x : dp){
                int cur = x + nums[i];
                temp[cur%3] = max(temp[cur%3], cur);
            }
            dp = temp;
        }
        return dp[0];
    }
};