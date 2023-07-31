class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap1(256);
        unordered_map<char, bool> umap2(256);

        for(int i=0;i<s.size();i++){
            if(umap1[s[i]] == 0 && umap2[t[i]] == false){
                umap1[s[i]] = t[i];
                umap2[t[i]] = true;
            }
            
        }

        for(int i=0;i<s.size();i++){
           if (umap1[s[i]] != t[i]) return false;
        }
        

        return true;
        

    }
};