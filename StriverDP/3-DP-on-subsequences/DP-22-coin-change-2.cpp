#include<bits/stdc++.h>


long f(int ind, int amt, int *coins, vector<vector<long>> &dp){
        // base
        if(ind == 0 || amt ==0){
            // if(amt == 0) return 1;
            if(amt % coins[0] == 0) return 1;
            return 0;
        }

        //memo
        if(dp[ind][amt] != -1) return dp[ind][amt];

        // nontake
        int nontake = f(ind-1, amt, coins, dp);
        int take=0;

        // take case only when amt >= coin[ind]
        if(coins[ind] <= amt){
            take = f(ind, amt-coins[ind], coins, dp);
        }

        return dp[ind][amt]= take+nontake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return f(n-1, value, denominations, dp);
}