class Solution {
public:
    int solve(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--;
            j++;
            count++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for(int i=0;i<n;i++){
            count += solve(s, i, i);
            count += solve(s, i, i+1);
        }

        return count;
    }
};