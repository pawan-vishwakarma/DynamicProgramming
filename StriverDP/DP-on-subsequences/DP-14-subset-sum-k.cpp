#include <bits/stdc++.h> 


// Problem-link -- https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM&count=25&page=1&search=subset&sort_entity=order&sort_order=ASC&customSource=studio_nav&attempt_status=COMPLETED


bool solve(int n, int k, vector<int> &arr, vector<vector<bool>> &dp){
    
    if(k==0){
        return true;
    }
    
    if(n == 0){
        return arr[0] == k;
    }

    if(dp[n][k] != 0){
        return dp[n][k];
    }

    bool nonpick = solve(n-1, k, arr, dp);
    bool pick = false;

    if(arr[n] <= k){
        pick = solve(n-1, k-arr[n], arr, dp);
    }
    
    return dp[n][k] = pick | nonpick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    // Memo -- Bottom-Up
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
        return solve(n-1, k, arr, dp);
    
    // Tabulation -- Top-Down
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = true ;
        }

        for(int i=1;i<n;i++){
            for(int j=1; j<=k; j++){

                bool nonpick = dp[i-1][j];
                bool pick= false;

                if(arr[i] <= j)
                    pick = dp[i-1][j-arr[i]];

                dp[i][j] = pick | nonpick;
                cout<<dp[i][j]<<" ";
                
            }
            cout<<endl;
        }

        return dp[n-1][k];

    // Space- Optimised
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));

        vector<bool> prev(k+1, 0);
        vector<bool> curr(k+1, 0);

        prev[0] = curr[0] =true;
        prev[arr[0]]=true;

        for(int i=0;i<n;i++){
            dp[i][0] = true ;
        }

        for(int i=1;i<n;i++){
            for(int j=1; j<=k; j++){

                bool nonpick = prev[j];
                bool pick= false;

                if(arr[i] <= j)
                    pick = prev[j-arr[i]];

                curr[j] = pick | nonpick;
                // cout<<dp[i][j]<<" ";
                
            }
            // cout<<endl;
            prev = curr;
        }

        return prev[k];
}