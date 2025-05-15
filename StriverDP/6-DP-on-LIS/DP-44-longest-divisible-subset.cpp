// refer-https://leetcode.com/problems/largest-divisible-subset/
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
    
            // hash fro backtracking the element
            vector<int> dp(n, 0), hash(n, 0);
            sort(nums.begin(), nums.end());
    
            int maxi=0, lastind= 0;
            for(int i=0; i<n; i++){
                hash[i]=i;
                for(int j=0; j<i; j++){
                    // checking if divisble
                    if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1){
                        dp[i]= dp[j]+1;
                        hash[i]= j;
                    }
                }
                //tracking lastind
                if(maxi < dp[i]) {
                    maxi= dp[i];
                    lastind= i;
                } 
            }
            vector<int> ans;
            ans.push_back(nums[lastind]);
            // generating the ans arr
            while(hash[lastind] != lastind){
                lastind= hash[lastind];
                ans.push_back(nums[lastind]);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };