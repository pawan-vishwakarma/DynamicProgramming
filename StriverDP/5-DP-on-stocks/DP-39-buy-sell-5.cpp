class Solution {
    public:
        int f(int ind, int buy, int n, vector<int> &val, vector<vector<int>> &dp){
    
            if(ind >= n) return 0;
    
            if(dp[ind][buy] != -1)return dp[ind][buy];
    
            int profit=0;
    
            if(buy){
                profit= max(-val[ind]+f(ind+1, 0, n, val, dp),
                            f(ind+1, 1, n, val, dp));
            }
            else{
                profit= max(val[ind]+f(ind+2, 1, n,val, dp), 
                            f(ind+1, 0, n, val, dp));
            }
            return dp[ind][buy]= profit;
        }
        int maxProfit(vector<int>& prices) {
            // val= prices;
                // vector<vector<int>>dp(prices.size()+1, vector<int>(2,-1));
                // return f(0, 1, prices.size(), prices, dp);
                vector<vector<int>>dp(prices.size()+2, vector<int>(2,0));
    
                for(int i= prices.size()-1; i>=0; i--){
                    dp[i][1] =max(-prices[i]+dp[i+1][0],
                            dp[i+1][1]);
                    dp[i][0]= max(prices[i]+dp[i+2][1],
                            dp[i+1][0]);
                }
                return dp[0][1];
        }
    };