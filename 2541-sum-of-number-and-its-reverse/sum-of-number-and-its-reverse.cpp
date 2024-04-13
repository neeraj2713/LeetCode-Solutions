class Solution {
private:
    int reverseNum(int num){
        if(num < 10) return num;
        int ans = 0;
        while(num > 0){
            int ld = num%10;
            ans = ans*10 + ld;
            num = num/10;
        }

        return ans;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 0) return true;
        for(int i=1;i<=num;i++){
            if(i + reverseNum(i) == num) return true; 
        }
        return false;
    }
};