#include <bits/stdc++.h> 

// count ways --- sum of recursion
// 2 strings therefore 2 params
// refer- https://www.naukri.com/code360/problems/distinct-subsequences_981277?leftPanelTabValue=SUBMISSION
string s1, s2;

int f(int ind1, int ind2, vector<vector<int>> &dp){
    // base
    if(ind2 < 0) return 1; // covered t
    if(ind1 < 0) return 0; // not found in s

    if(dp[ind1][ind2] != -1)return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2]){
        return dp[ind1][ind2]= f(ind1-1, ind2-1, dp)+f(ind1-1, ind2, dp);
    }
    return dp[ind1][ind2]= f(ind1-1, ind2, dp);
}

int numDistinct(string S, string T) {
    s1= S;
    s2= T;
    int l1= S.size();
    int l2= T.size();

        // vector<vector<int>>dp(l1+1, vector<int>(l2+1, -1));

        // return f(l1-1, l2-1, dp);
    
    // tabulation
        // vector<vector<int>>dp(l1+1, vector<int>(l2+1, 0));
        // for(int i=0; i<=l1; i++)
        //     dp[i][0] = 1;
        
        // for(int i=1; i<=l1; i++){
        //     for(int j=1; j<=l2; j++){
        //         if(s1[i-1] == s2[j-1])
        //             dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        //         else
        //             dp[i][j] = dp[i-1][j];
        //     }
        // }

        // return dp[l1][l2];
    
    // space-optimised
        // vector<vector<int>>dp(l1+1, vector<int>(l2+1, 0));
        vector<int> prev(l2+1, 0), curr(l2+1, 0);
        // for(int i=0; i<=l1; i++)
        curr[0] = 1;
        prev[0]=1;
        
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s1[i-1] == s2[j-1])
                    curr[j] = prev[j-1]+prev[j];
                else
                    curr[j] = prev[j];
            }
            prev= curr;
        }

        return prev[l2];
    


}
