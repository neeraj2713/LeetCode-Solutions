class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> st;

        for(int num : nums1) st.insert(num);

        for(int num : nums2){
            if(st.find(num) != st.end()) {
                ans.push_back(num);
                st.erase(num);
            }
        }

        return ans;
    }
};