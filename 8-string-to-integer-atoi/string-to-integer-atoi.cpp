class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        int i = 0;

        while(s[i] == ' ') i++;

        if(i<s.size() && (s[i] == '+' || s[i] == '-')){
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] > '7')){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            ans = ans*10 + (s[i] - '0');
            i++;
        }
        
        return ans*sign;
    }
};