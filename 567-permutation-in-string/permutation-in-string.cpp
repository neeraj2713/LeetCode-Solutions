class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cur(26), goal(26);
        if(s1.length() > s2.length()) return false;
        for(char c : s1) goal[c-'a']++;

        for(int i=0;i<s2.length();i++){
            cur[s2[i] - 'a']++;
            if(i >= s1.size()) {
                cur[s2[i-s1.size()] - 'a']--;
            }
            if(goal == cur) return true;
        }

        return false;

    }
};