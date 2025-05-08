class Solution {
    public:
        int f(int ind, int buy, vector<int>& prices, int fee, int n, vector<vector<int>> &dp){
            if(ind == n) return 0;
            if(dp[ind][buy] != -1)return dp[ind][buy];
            int profit= 0;
            if(buy){
                profit= max(-prices[ind]+f(ind+1, 0, prices, fee, n, dp), 
                            f(ind+1, 1, prices, fee, n, dp));
            }
            else{
                profit= max(prices[ind]-fee+f(ind+1, 1, prices, fee, n, dp), 
                            f(ind+1, 0, prices, fee, n, dp));
            }
    
            return dp[ind][buy]= profit;
        }
        int maxProfit(vector<int>& prices, int fee) {
                // vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
                // return f(0, 1, prices, fee, prices.size(),dp);
            // tabulation
                vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
                int n= prices.size();
                for(int ind= n-1; ind>=0; ind--){
                    dp[ind][1]= max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
                    dp[ind][0]= max(prices[ind]-fee+dp[ind+1][1], dp[ind+1][0]);
                }
    
                return dp[0][1];
        }
    };