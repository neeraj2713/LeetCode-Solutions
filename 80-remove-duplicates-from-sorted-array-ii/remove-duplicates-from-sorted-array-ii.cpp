class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        while(r < n){
            int count = 1;
            while((r+1) < n && nums[r] == nums[r+1]){
                count++;
                r++;
            }

            int i = 0;
            int mini = min(count, 2);
            while(i < mini){
                nums[l] = nums[r];
                l++;
                i++;
            }
            r++;
        }

        return l;
    }
};