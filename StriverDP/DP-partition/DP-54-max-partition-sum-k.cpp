class Solution {
    // refer- https://leetcode.com/problems/partition-array-for-maximum-sum/
public:
    int f(int ind, int k, int n, vector<int> &arr, vector<int> &dp){
        if(ind == n) return 0;

        if(dp[ind] != -1)return dp[ind];

        int len=0, maxi= INT_MIN, maxisum= INT_MIN;
        for(int j= ind; j<min(k+ind, n); j++){
            len++;
            maxi= max(maxi, arr[j]);
            int sum= (maxi*len)+ f(j+1, k, n, arr, dp);
            maxisum= max(maxisum, sum);
        }
        return dp[ind]= maxisum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        // vector<int> dp(n+1, -1);
        // return f(0, k, n, arr, dp);
        // bottomup tabulation

        vector<int> dp(n+1, 0);
        for(int ind=n-1; ind>=0; ind--){
            int len=0, maxi= INT_MIN, maxisum= INT_MIN;
            for(int j= ind; j<min(k+ind, n); j++){
                len++;
                maxi= max(maxi, arr[j]);
                int sum= (maxi*len)+ dp[j+1];
                maxisum= max(maxisum, sum);
            }
            dp[ind]= maxisum;
        }
        return dp[0];
    }
};