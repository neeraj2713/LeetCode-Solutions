class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(auto s:strs){
            string word = s;
            sort(word.begin(), word.end());
            mpp[word].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto x:mpp){
            ans.push_back(x.second);
        }

        return ans;
    }
};