class Solution {
    // refer- https://leetcode.com/problems/palindrome-partitioning-ii/
public:
    bool ispalin(int i, int j, string s){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int ind, int n, string s, vector<int> &dp){
        if(ind == n) return 0;    

        if(dp[ind] != -1) return dp[ind];

        int mincuts= INT_MAX;

        for(int j=ind; j<n; j++){
            if(ispalin(ind, j, s)){
                int cuts= 1+f(j+1, n, s, dp);
                mincuts= min(cuts, mincuts);
            }
        }
        return dp[ind]= mincuts;
    }
    int minCut(string s) {
        int n= s.length();
        vector<int> dp(n+2, -1);
        // return f(0, n, s, dp)-1;

        // tabulation
        vector<vector<bool>> ispalin(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || ispalin[i + 1][j - 1])) {
                    ispalin[i][j] = true;
                }
            }
        }
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            int mincuts= INT_MAX;
            for(int j= i; j<n; j++){
                if(ispalin[i][j]){
                    int cuts= 1+dp[j+1];
                    mincuts= min(cuts, mincuts);
                }
            }
            dp[i]= mincuts;
        }
        return dp[0]-1;
    }
};