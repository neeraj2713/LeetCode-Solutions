class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n < 10) return {};
        vector<string> ans;
        unordered_map<string, int> mpp;

        for(int i=0;i<=n-10;i++){
            string ss = s.substr(i,10);
            mpp[ss]++;
            if(mpp[ss] == 2){
                ans.push_back(ss);
            }
        }

        return ans;

    }
};