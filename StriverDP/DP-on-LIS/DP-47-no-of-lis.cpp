class Solution {
    public:
    // refer- https://leetcode.com/problems/number-of-longest-increasing-subsequence/
        int findNumberOfLIS(vector<int>& nums) {
            int n= nums.size();
            vector<int> dp(n, 1), cnt(n, 1);
            int maxi=1;
            for(int ind=1; ind<n; ind++){
                for(int j=0; j<ind; j++){
                    if(nums[ind] > nums[j] && dp[ind] < 1+dp[j]){
                        dp[ind]= 1+dp[j];
                        cnt[ind]= cnt[j];
                    }
                    else if(nums[ind] > nums[j] && dp[ind] == 1+dp[j]){
                        cnt[ind] += cnt[j];
                    }
                }
                maxi= max(maxi, dp[ind]);
            }
            int ans=0;
            for(int i=0; i<n; i++){
                if(dp[i] == maxi) ans += cnt[i];
            }
            return ans;
        }
    };