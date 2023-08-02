class Solution {
public:
    int myAtoi(string s) {
        int num = 0, i=0, sign = 1;

        //removing leading white spaces
        while(s[i] == ' ') i++;

        //checking the sign of number
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            sign = s[i]== '+' ?1  : -1;
            i++;
        }

        //calculating ans
        while(i<s.size() && isdigit(s[i])){
            if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7')){
                return sign==-1? INT_MIN:INT_MAX;
            }

            num = num*10 + (s[i]-'0');
            i++;
        }

        //returning ans
        return num*sign;
    }
};