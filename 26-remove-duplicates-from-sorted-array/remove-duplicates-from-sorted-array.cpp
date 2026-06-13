class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0;
        int j = i+1;

        while(j<n){
            if(nums[j] == nums[j-1]){
                j++;
                continue;
            } else {
                nums[i+1] = nums[j];
                i++;
                j++;
            }

        }

        return i+1;
    }
};