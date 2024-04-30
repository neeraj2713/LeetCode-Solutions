class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxLen = 0;
        set<char> st; 

        while(j<n){
            if(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            } else {
                maxLen = max(maxLen, j-i+1);
                st.insert(s[j]);
                j++;
            }
        }

        return maxLen;
    }
};