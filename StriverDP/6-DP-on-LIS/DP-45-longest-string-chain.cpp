//refer- https://leetcode.com/problems/longest-string-chain/description/
class Solution {
    public:
        bool compare(string a, string b){
            if(a.size() != b.size()+1)return false;
            int n=a.length();
            int m=b.length();
            int i=0,j=0;
    
            while(i<n){
                if(a[i] == b[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            if(i == n and j == m)return true;
            return false;
        }
    
        static bool comp(string &a1, string &a2){
            return a1.size()<a2.size();
        }
    
        int longestStrChain(vector<string>& words) {
            // sort as per length
            sort(words.begin(), words.end(), comp);
    
            //using lis code 
            int n= words.size(), maxi=1;
            vector<int> dp(n, 1);
    
            for(int i=1; i<n; i++){
                for(int j=0; j<i; j++){
                    // checking string if 1 char > and 1 char diff
                    if(compare(words[i], words[j]) && dp[i] < dp[j]+1){
                        dp[i]= 1+dp[j];
                    }
                }
                if(maxi < dp[i]) maxi= dp[i];
            }
            return maxi;
        }
    };