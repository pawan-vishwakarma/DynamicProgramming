#include<bits/stdc++.h>
// refer- https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459?leftPanelTabValue=SUBMISSION

int nn;
int f(int ind, int prev,int arr[], vector<vector<int>> &dp){

    //base 
    if(ind == nn) return 0;

    //memo -- prev=1 bcz -1 as prev val exist
    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

    // non-pick case
    int notpick= f(ind+1, prev, arr, dp);

    //pick
    int pick = INT_MIN;

    if(prev == -1 || arr[ind] > arr[prev]){
        pick = 1+f(ind+1, ind, arr, dp);
    }

    dp[ind][prev+1]= max(pick, notpick);
    return dp[ind][prev+1];
}



int longestIncreasingSubsequence(int arr[], int n)
{
    nn = n;
        // vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        // return f(0, -1,arr, dp);
        // vector<int>after(n+1, 0), curr(n+1, 0);

        // for(int ind=n-1; ind>=0; ind--){
        //     for(int prev=ind-1; prev>=-1; prev--){

        //         int notpick= after[prev+1];

        //         //pick
        //         int pick = INT_MIN;

        //         if(prev == -1 || arr[ind] > arr[prev]){
        //             pick = 1+after[ind+1];
        //         }

        //         curr[prev+1]= max(pick, notpick);
        //     }
        //     after= curr;
        // }

        // return after[-1+1];
    // lis 1d

        vector<int>dp(n+1, 1), hash(n,0);
        int maxi=1, prevInd=0;

        for(int ind=0; ind<n; ind++){
            hash[ind]=ind;
            for(int prev=0; prev<ind; prev++){ 
                if(arr[ind] > arr[prev] && dp[ind] < 1+dp[prev]){
                    dp[ind]= 1+dp[prev];
                    hash[ind]= prev;    
                }
            }
            if(maxi < dp[ind]){
                maxi= dp[ind];
                prevInd= ind;
            }
        }

        vector<int> print;

        while(hash[prevInd] != prevInd){
            print.push_back(arr[prevInd]);
            prevInd= hash[prevInd];
        }

        for(auto it: print){
            cout<<it<<" ";
        }
        cout<<endl;
        // return maxi;
}
