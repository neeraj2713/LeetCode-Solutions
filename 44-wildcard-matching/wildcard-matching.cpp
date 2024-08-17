class Solution {
public:

    bool isMatch(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector <vector<bool>> dp(n+1,vector<bool>(m+1,false));


        for(int j=1 ; j<= m ; j++){
            bool flag = true;
            for(int index = 1 ;index <=j ; index++){
                if(t[index-1] != '*'){
                    dp[0][j] = false;
                    flag = false;
                    break;
                }
            }
            if(flag){
                dp[0][j] = true;
            }
        }

        dp[0][0] = true;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] =  dp[i-1][j-1];
                }else{
                    if(t[j-1] == '?'){
                        dp[i][j] = dp[i-1][j-1];
                    }else if(t[j-1] == '*'){
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }
};