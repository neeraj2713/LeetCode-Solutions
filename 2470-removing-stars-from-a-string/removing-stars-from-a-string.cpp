class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char> st;
        for(char c : s){
            if(c == '*' && !st.empty()){
                st.pop();
            } else {
                st.push(c);
            }
        }

        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};