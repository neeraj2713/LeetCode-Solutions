class Solution {
private:
    int char2num(char a) {
        switch (a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = char2num(s[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            if (char2num(s[i]) < char2num(s[i + 1])) {
                ans -= char2num(s[i]);
            } else {
                ans += char2num(s[i]);
            }
        }

        return ans;
    }
};