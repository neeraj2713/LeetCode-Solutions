class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastGood = n-1;

        for(int i=n-1;i>=0;i--){
            if(nums[i] + i >= lastGood ){
                lastGood = i;
            }
        }

        return lastGood == 0;
    }
};