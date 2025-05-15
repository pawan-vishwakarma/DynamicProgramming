class Solution {
    public:
    
        int solve(int i, vector<int> &nums, vector<int> &dp){
            if(i == 0) return nums[0];
    
            if(i<0) return 0;
    
            if(dp[i] != -1) return dp[i];
    
            int pick = INT_MIN;
    
            if(i<nums.size())
                pick = nums[i]+solve(i-2, nums, dp);
    
            int nonpick = solve(i-1, nums, dp);
    
            return dp[i] = max(pick, nonpick);
        }
        int rob(vector<int>& nums) {
            int n= nums.size();
    
            if(n == 1) return nums[0] ;
            if(n == 2) return max(nums[0], nums[1]) ;
    
            vector<int> dp(n+1, -1);
    
            dp[0] = nums[0] ;
            dp[1] = nums[1] ;
    
            for(int i=1;i<n;i++){
                int pick = nums[i];
                if(i == 1){
                    pick += 0;
                }
                else{
                    pick += dp[i-2];
                }
                
                int non = dp[i-1];
    
                dp[i] = max(pick, non);
            }
    
            return dp[n-1];
    
        }
    };