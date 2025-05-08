#include<bits/stdc++.h>

long f(int ind, int buy, long *val, int n, vector<vector<int>> &dp){
    
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    long profit= 0;

    if(buy){
        profit = max(-val[ind]+f(ind+1, 0, val,n, dp), 
                        f(ind+1, 1, val, n, dp));
    }
    else{
        profit = max(val[ind]+f(ind+1, 1, val, n, dp), 
                    f(ind+1, 0, val, n, dp));
    }

    return dp[ind][buy]= profit;
}




long getMaximumProfit(long *values, int n)
{
    // rec+memo
        // vector<vector<int>> dp(n+1, vector<int>(2,-1));
        // return f(0, 1, values, n, dp);

    // tabulation
        // vector<vector<long >> dp(n+1, vector<long>(2, 0));
        // dp[n][0]= 0;
        // dp[n][1]= 0;

        // for(int ind=n-1; ind>=0 ;ind--){
        //     for(int buy=0; buy<=1; buy++){
        //         long profit=0 ;
        //         if(buy){
        //             profit = max(-values[ind]+dp[ind+1][0], 
        //                             dp[ind+1][1]);
        //         }
        //         else{
        //             profit = max(values[ind]+dp[ind+1][1], 
        //                         dp[ind+1][0]);
        //         }

        //         dp[ind][buy]= profit;
        //     }
        // }
        // return dp[0][1];
    // space-optimised
        // vector<vector<long >> dp(n+1, vector<long>(2, 0));
        vector<long> curr(2, 0), prev(2,0);
        prev[0]= 0;
        prev[1]= 0;

        for(int ind=n-1; ind>=0 ;ind--){
            for(int buy=0; buy<=1; buy++){
                long profit=0 ;
                if(buy){
                    profit = max(-values[ind]+prev[0], 
                                    prev[1]);
                }
                else{
                    profit = max(values[ind]+prev[1], 
                                prev[0]);
                }

                curr[buy]= profit;
            }
            prev = curr;
        }
        return prev[1];

}
