class Solution {
public:
    vector<int> sides = {0,0,0,0};
    bool helper(vector<int>& nums, int i, int n, int target){
        if(i == n) return true;

        for(int k=0;k<4;k++){
            if(sides[k] + nums[i] <= target){
                sides[k] += nums[i];
                if(helper(nums, i+1, n, target)) return true;
                sides[k] -= nums[i];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(!n) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4 != 0) return false;
        int target = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());
        return helper(matchsticks, 0, n, target);
    }
};