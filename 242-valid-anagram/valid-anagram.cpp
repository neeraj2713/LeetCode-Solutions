class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map1(256, 0);
        vector<int> map2(256, 0);

        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            map2[t[i]]++;
        }

        for(int i=0;i<256;i++){
            if(map1[i] != map2[i]) return false;
        }
        
        return true;

    }
};