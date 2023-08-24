class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        backtrack(0, s, output, ans);
        return ans;
    }

    void backtrack(int index, string s, vector<string> output, vector<vector<string>>& ans){
        if(index >= s.size()){
            ans.push_back(output);
            return;
        }


        for(int i=index;i<s.size();i++){
            if(isPalindrome(s, index, i)){
                output.push_back(s.substr(index, i-index+1));
                backtrack(i+1, s, output, ans);
                output.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }

        return true;
    }
};