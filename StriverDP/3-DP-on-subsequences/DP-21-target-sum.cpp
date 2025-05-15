#include <bits/stdc++.h> 
 
using namespace std;

// REFER - https://www.naukri.com/code360/problems/target-sum_4127362?leftPanelTabValue=SUBMISSION

int mod=1e9+7;

int solve(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    
    
    if(n == 0){
        if(k ==0 and arr[0] == 0)return 2;
        if(k == 0 || k == arr[0]) return 1;
        return 0;
    }

    if(dp[n][k] != -1){
        return dp[n][k];
    }

    int nonpick = solve(n-1, k, arr, dp);
    int pick = 0;

    if(arr[n] <= k){
        pick = solve(n-1, k-arr[n], arr, dp);
    }
    
    dp[n][k] = pick + nonpick;
    return dp[n][k];
}

int findWays(vector<int>& arr, int k)
{
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(k+1, 0));
        // // return solve(n-1, k, arr, dp);
        // if(arr[0] == 0)dp[0][0] =2;
        // else dp[0][0] = 1;

        // // for(int i=0; i<n; i++){
        // //     dp[i][0] = 1;
        // // }
        // // dp[0][0]=2;

        // if(arr[0] <= k and arr[0] != 0) dp[0][arr[0]] = 1;

        // for(int i=1; i<n ;i++){
        //     for(int j=0; j<=k; j++){
        //         int nonpick = dp[i-1][j]%mod;
        //         int pick = 0;
        //         if(arr[i] <= j){
        //             pick = dp[i-1][j-arr[i]]%mod;
        //         }
        //         dp[i][j] = (pick+nonpick)%mod;
        //     }
        // }

        // return dp[n-1][k];
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(k+1, 0));
    // return solve(n-1, k, arr, dp);

    vector<int> prev(k+1, 0), curr(k+1, 0);
    if(arr[0] == 0)prev[0] =2;
    else prev[0] = 1;

    // for(int i=0; i<n; i++){
    //     dp[i][0] = 1;
    // }
    // dp[0][0]=2;

    if(arr[0] <= k and arr[0] != 0) prev[arr[0]] = 1;

    for(int i=1; i<n ;i++){
        for(int j=0; j<=k; j++){
            int nonpick = prev[j]%mod;
            int pick = 0;
            if(arr[i] <= j){
                pick = prev[j-arr[i]]%mod;
            }
            curr[j] = (pick+nonpick)%mod;
        }
        prev= curr;
    }

    return prev[k];
}




int countPartitions(int n, int d, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int target = (sum-d)/2;
    if(sum-d < 0 || (sum-d )%2) return 0;
    
    return findWays(arr, target);
}




int targetSum(int n, int target, vector<int>& arr) {
   return countPartitions(n, target, arr);
}
