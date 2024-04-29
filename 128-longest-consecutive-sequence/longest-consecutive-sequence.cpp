class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        //putting all elements into set
        unordered_set<int> st;
        for(auto x : nums) st.insert(x);

        //actual logic
        for(auto x : nums){
            int it = x;
            if(st.find(it-1) == st.end()){
                int longest = 1;
                while(st.find(it+1) != st.end()){
                    longest++;
                    it++;
                }
                ans = max(ans, longest);
            }
            

        }
        return ans;
    }
};