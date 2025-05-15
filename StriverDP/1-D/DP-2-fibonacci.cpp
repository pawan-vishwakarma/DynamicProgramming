class Solution {
    public:
        // refer- https://leetcode.com/problems/fibonacci-number/description/
        int f(int i, vector<int> &dp){
            if(i == 0 ) return 0;
            if(i == 1) return 1;
    
            if(dp[i] != -1) return dp[i];
    
            return dp[i]= f(i-1, dp)+f(i-2, dp);
        }
        int fib(int n) {
            vector<int> dp(n+1, -1);
            return f(n, dp);
        }
    };