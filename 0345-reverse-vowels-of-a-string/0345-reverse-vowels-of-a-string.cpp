class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i<j){
            while(!isVowel(s[i]) && i<j) i++;
            while(!isVowel(s[j]) && i<j) j--;
            swap(s[i],s[j]);
            i++;
            j--;
        }

        return s;
    }
};

