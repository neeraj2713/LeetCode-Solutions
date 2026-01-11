class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++) {
            mpp[nums[i]]++;
        }

        for(auto &p: mpp){
            if(p.second > 1) return true;
        }

        return false;
    }
};