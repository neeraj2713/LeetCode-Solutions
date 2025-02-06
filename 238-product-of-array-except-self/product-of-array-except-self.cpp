class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int rp = 1;

        for(int i=0;i<nums.size();i++){
            ans[i] = rp;
            rp = rp*nums[i];
        }

        rp = 1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] = ans[i]*rp;
            rp = rp*nums[i];
        }

        return ans;

    }
};