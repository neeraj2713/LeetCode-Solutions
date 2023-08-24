class Solution {
private:
    void backtrack(string digits, string output, int index, vector<string>& ans, string mapping[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            backtrack(digits, output, index+1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, output, index, ans, mapping);
        return ans;
    }


};