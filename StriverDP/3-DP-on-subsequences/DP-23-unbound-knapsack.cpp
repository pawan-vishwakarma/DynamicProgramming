#include<bits/stdc++.h>

int f(int n, int wei, vector<int> &v, vector<int> &w,vector<vector<int>> &dp)
{
    if(n == 0){
        return (wei/w[0])*v[0];
    }

    if(dp[n][wei] != -1) return dp[n][wei];

    //nontake
    int nontake = f(n-1, wei, v, w, dp);
    int take = -1e9;

    if(w[n] <= wei){
        take = v[n]+f(n, wei-w[n], v, w, dp);
    }

    return dp[n][wei]= max(take, nontake);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // vector<vector<int>>dp(n, vector<int>(w+1, -1));
    // return f(n-1, w, profit, weight, dp);
        // vector<vector<int>>dp(n, vector<int>(w+1, -1));
        // for(int i=0; i<=w; i++){
        //     dp[0][i] = i/weight[0]*profit[0] ;
        // }

        // for(int i=1; i<n; i++){
        //     for(int j=0; j<=w; j++){

        //         int nontake = dp[i-1][j];
        //         int take = -1e9;

        //         if(weight[i] <= j){
        //             take = profit[i]+dp[i][j-weight[i]];
        //         }

        //         dp[i][j]= max(take, nontake);
        //     }
        // }

        // return dp[n-1][w];

    // space-optimised

        // vector<int> prev(w+1, 0), curr(w+1, 0);

        // for(int i=0; i<=w; i++){
        //     prev[i] = i/weight[0]*profit[0] ;
        // }

        // for(int i=1; i<n; i++){
        //     for(int j=0; j<=w; j++){

        //         int nontake = prev[j];
        //         int take = -1e9;

        //         if(weight[i] <= j){
        //             take = profit[i]+curr[j-weight[i]];
        //         }

        //         curr[j]= max(take, nontake);
        //     }
        //     prev=curr;
        // }

        // return prev[w];

    // 1 array optimised

        vector<int> prev(w+1, 0);

        for(int i=0; i<=w; i++){
            prev[i] = i/weight[0]*profit[0] ;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=w; j++){

                int nontake = prev[j];
                int take = -1e9;

                if(weight[i] <= j){
                    take = profit[i]+prev[j-weight[i]];
                }

                prev[j]= max(take, nontake);
            }
            // prev=curr;
        }

        return prev[w];

}