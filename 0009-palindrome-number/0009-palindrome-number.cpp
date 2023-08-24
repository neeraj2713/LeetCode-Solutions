class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int temp = x;
        long long int reverse = 0;
        while(temp > 0){
            int ld = temp%10;
            reverse = reverse*10 + ld;
            temp = temp/10;
        }

        return reverse == x;
    

    }
};