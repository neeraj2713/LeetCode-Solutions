class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=n*2-1;i>=0;i--){
            //first step
            while(!st.empty() && nums[st.top()] <= nums[i%n]) st.pop();

            //second step
            ans[i%n] = st.empty() ? -1 : nums[st.top()];

            //third step
            st.push(i%n);
        }

        return ans;
    }
};