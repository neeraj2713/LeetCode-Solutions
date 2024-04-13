class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        //step 1 : initialization of dp array
        vector<int> dp(n+1);

        //step 2 : inserting base case in dp array
        dp[0] = 0;
        dp[1] = 1;

        //step 3 : tabulation method
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        
    }
};