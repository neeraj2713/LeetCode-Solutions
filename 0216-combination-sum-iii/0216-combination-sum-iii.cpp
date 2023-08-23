class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(k, n, 1, output, ans);
        return ans;
    }

    void backtrack(int k, int n, int index, vector<int>& output, vector<vector<int>>& ans){
        if(output.size() == k){
            if(n == 0){
                ans.push_back(output);
                return;
            }
            return;
        }


        for(int i=index;i<=9;i++){
            output.push_back(i);
            backtrack(k, n-i, i+1, output, ans);
            output.pop_back();
        }

        
    }
};