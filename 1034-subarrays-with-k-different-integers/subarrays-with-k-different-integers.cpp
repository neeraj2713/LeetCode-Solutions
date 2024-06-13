class Solution {
private:
    int solver(vector<int>& nums, int k){
        int count = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mpp;

        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solver(nums, k) - solver(nums, k-1);
    }
};