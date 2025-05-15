#include <bits/stdc++.h> 

// n*2*K approach -- prev buy-sell-3 n*4 approach

//refer - https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_1080698?leftPanelTabValue=PROBLEM

vector<int> val;
int f(int ind, int transno, int n, int k, vector<vector<int>> &dp){
    // base
    if(ind == n || transno == 2*k) return 0;

    if(dp[ind][transno] != -1) return dp[ind][transno];

    int profit=0;

    if(transno%2 == 0){ // buy case B S B S ie 0th and 2nd ie even
        profit = max(-val[ind]+f(ind+1, transno+1, n, k, dp), 
                        f(ind+1, transno, n, k, dp));
    }
    else{
        profit = max(val[ind]+f(ind+1, transno+1, n, k, dp), 
                        f(ind+1, transno, n, k, dp));
    }

    return dp[ind][transno]= profit;
}


int maximumProfit(vector<int> &prices, int n, int k)
{
    val= prices;
        // vector<vector<int>>dp(n+1, vector<int>(2*k+1, -1));
        // return f(0, 0, n, k, dp);

    // tabulaiton
        // vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
        // for(int ind= n-1; ind>=0; ind--){
        //     for(int transno= 2*k-1; transno>=0; transno--){

        //         int profit=0;
        //         if(transno%2 == 0){ // buy case B S B S ie 0th and 2nd ie even
        //             profit = max(-val[ind]+dp[ind+1][transno+1], 
        //                             dp[ind+1][transno]);
        //         }
        //         else{
        //             profit = max(val[ind]+dp[ind+1][transno+1], 
        //                             dp[ind+1][transno]);
        //         }

        //         dp[ind][transno] = profit;
        //     }
        // }
        // return dp[0][0];

    // space optimised
        vector<int> after(2*k+1, 0), curr(2*k+1, 0);

        for(int ind= n-1; ind>=0; ind--){
            for(int transno= 2*k-1; transno>=0; transno--){

                int profit=0;
                if(transno%2 == 0){ // buy case B S B S ie 0th and 2nd ie even
                    profit = max(-val[ind]+after[transno+1], 
                                    after[transno]);
                }
                else{
                    profit = max(val[ind]+after[transno+1], 
                                    after[transno]);
                }

                curr[transno] = profit;
            }
            after= curr;
        }
        return after[0];
}
