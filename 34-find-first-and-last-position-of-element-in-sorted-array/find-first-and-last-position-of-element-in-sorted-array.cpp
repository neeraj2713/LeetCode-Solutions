class Solution {
private:
    int firstOcc(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            } else if(nums[mid] > target){
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }

    int lastOcc(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            } else if(nums[mid] > target){
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        ans[0] = firstOcc(nums, target);
        ans[1] = lastOcc(nums, target);

        return ans;
    }
};