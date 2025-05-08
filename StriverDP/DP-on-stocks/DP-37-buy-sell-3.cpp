#include<bits/stdc++.h>

int n;
vector<int> val;

int f(int ind, int buy, int cap, vector<vector<vector<int>>> &dp){

    // base
    if(ind == n) return 0; // nothing matter if price arry exhaushted
    if(cap == 0) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit=0;

    // rec
    if(buy){
        profit= max(-val[ind]+f(ind+1, 0, cap, dp), f(ind+1, 1, cap, dp)); // cap not changes as transc=buy+sell yet not finished
    }
    else{ // sell case
        profit= max(val[ind]+f(ind+1, 1, cap-1, dp), f(ind+1, 0, cap, dp));
    }

    return dp[ind][buy][cap]= profit;

}

int maxProfit(vector<int>& prices)
{
    n= prices.size();
    val= prices;
   
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // return f(0, 1, 2, dp);

    // tabulation
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // // base cases
        // // cap=0 means ind and buy can be anythingso
        // for(int ind=0; ind<n; ind++){
        //     for(int buy=0; buy<2; buy++){
        //         dp[ind][buy][0]= 0;
        //     }
        // }

        // // similar ind == n , buy and cap can be anything
        // for(int buy= 0; buy<2; buy++){
        //     for(int cap= 0; cap<3; cap++){
        //         dp[n][buy][cap]= 0;
        //     }
        // }


        // // other cases
        // for(int ind=n-1; ind>=0; ind--){
        //     for(int buy= 0; buy<=1; buy++){
        //         for(int cap=1; cap<3; cap++){
        //             int profit=0;
        //             // rec
        //             if(buy){
        //                 profit= max(-val[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]); // cap not changes as transc=buy+sell yet not finished
        //             }
        //             else{ // sell case
        //                 profit= max(val[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
        //             }

        //             dp[ind][buy][cap]= profit;
        //         }
        //     }
        // }

        // return dp[0][1][2];

    //space-optimsed
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        // // base cases
        // // cap=0 means ind and buy can be anythingso
        // for(int ind=0; ind<n; ind++){
        //     for(int buy=0; buy<2; buy++){
        //         dp[ind][buy][0]= 0;
        //     }
        // }

        // // similar ind == n , buy and cap can be anything
        // for(int buy= 0; buy<2; buy++){
        //     for(int cap= 0; cap<3; cap++){
        //         dp[n][buy][cap]= 0;
        //     }
        // }


        // other cases
        for(int ind=n-1; ind>=0; ind--){
            for(int buy= 0; buy<=1; buy++){
                for(int cap=1; cap<3; cap++){
                    int profit=0;
                    // rec
                    if(buy){
                        profit= max(-val[ind]+prev[0][cap], prev[1][cap]); // cap not changes as transc=buy+sell yet not finished
                    }
                    else{ // sell case
                        profit= max(val[ind]+prev[1][cap-1], prev[0][cap]);
                    }

                    curr[buy][cap]= profit;
                }
            }
            prev= curr;
        }

        return prev[1][2];

}
