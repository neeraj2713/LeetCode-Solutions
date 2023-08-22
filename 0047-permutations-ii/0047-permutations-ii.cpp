class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& ans, set<vector<int>>& s){
        if(index >= nums.size()){
            if(s.find(nums) == s.end()){
                ans.push_back(nums);
            }
            s.insert(nums);
            return;
        }

        for(int j=0;j<=index;j++){
            swap(nums[index], nums[j]);
            backtrack(nums, index+1, ans, s);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        backtrack(nums, 0, ans, s);
        return ans;
    }
};