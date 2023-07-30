class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> bucket1;
        map<char, int> bucket2;

        for(char c:s){
            bucket1[c]++;
        }
        
        for(char c:t){
            bucket2[c]++;
        }

        return bucket1==bucket2;
        
    }
};