class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s;

        for(auto x : nums) s.insert(x);

        for(auto x : nums){
            int it = x;
            if(s.find(it-1) == s.end()){
                int longest = 1;
                while(s.find(it+1) != s.end()){
                    longest++;
                    it++;
                }
                ans = max(longest, ans);
            }
            
        }

        return ans;
    }
};