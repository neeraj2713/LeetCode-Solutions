class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int maxCount = 0;

        while(j < s.size()){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                count++;
            }

            if(j-i+1 > k) {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count--;
                i++;
            }
            
            maxCount = max(maxCount, count);
            j++;
        }

        return maxCount;
    }
};