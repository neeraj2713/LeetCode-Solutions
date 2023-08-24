class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        backtrack(0, 0, n, output, ans);
        return ans;

    }

    void backtrack(int open, int close, int total, string output, vector<string>& ans){
        //base case
        if(open == total && close == total){
            ans.push_back(output);
            return;
        }


        //add open brackets
        if(open < total){
            backtrack(open+1, close, total, output + "(", ans);
        }

        //add closed brackets
        if(open > close){
            backtrack(open, close+1, total, output + ")", ans);
        }
    }
};