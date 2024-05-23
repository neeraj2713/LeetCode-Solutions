class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int index = n;
        for(int i=n-1;i>=0;i--){
            if(num[i]%2 == 0){
                index--;
            } else {
                break;
            }
            
        }

        return num.substr(0, index);
    }
};