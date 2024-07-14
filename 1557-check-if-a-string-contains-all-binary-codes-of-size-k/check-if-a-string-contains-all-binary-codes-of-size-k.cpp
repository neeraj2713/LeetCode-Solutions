class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int i=0;
        int j=0;

        while(j<s.size()){
            if((j-i+1) == k){
                st.insert(s.substr(i, k));
                i++;
            }
            j++;
        }

        return st.size() == pow(2, k);
    }
};