class Solution {
private:
    bool getFibo(string& s, int i, long long a, long long b, int n){
        if(i == s.length()) return n>2;
        
        long long num = 0;
        for(int x=i;x<s.length();x++){
            if(num > pow(10, 17)) break;
            num = num*10 + s[x] - '0';

            bool check = false;
            if(n<2) check = getFibo(s, x+1, b, num, n+1);
            else if(a+b==num) check = getFibo(s, x+1, b, num, n+1);

            if(check) return true;

            if(num == 0) break;
        }

        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        return getFibo(num, 0, 0, 0, 0);
    }
};