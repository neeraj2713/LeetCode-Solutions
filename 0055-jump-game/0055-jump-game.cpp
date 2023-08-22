class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGood = nums.size()-1;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] + i >= lastGood){
                lastGood = i;
            }
        }

        return lastGood == 0;
    }
};