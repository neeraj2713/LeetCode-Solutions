class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0;i<n;i++){
            map<char, int> m;
            multiset<int> st;
            for(int j=i;j<n;j++){
                if(m.find(s[j]) != m.end()){
                    st.erase(st.find(m[s[j]]));
                }
                m[s[j]]++;
                st.insert(m[s[j]]);
                ans += (*st.rbegin() - *st.begin());
            }
        }

        return ans;
    }
};