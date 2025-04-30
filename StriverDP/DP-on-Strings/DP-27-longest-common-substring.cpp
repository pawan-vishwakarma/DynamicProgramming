string s1, s2;

// REFER - http://naukri.com/code360/problems/longest-common-substring_1235207?interviewProblemRedirection=true&search=longest%20common&attempt_status=COMPLETED

int lcs(string &str1, string &str2){
    s1 = str1;
    s2 = str2;
    int l1=s1.size();
    int l2=s2.size();
    // tabulation
        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // int maxi=-1e9;
        // for(int i=1; i<=l1; i++){
        //     for(int j=1; j<=l2; j++){
        //         if(s1[i-1] == s2[j-1]){
        //             dp[i][j] = 1+dp[i-1][j-1];
        //             maxi = max(maxi, dp[i][j]);
        //         }
        //     }
        // }
        // return maxi;

    // space-optimsed
        vector<int> prev(l2+1, 0);
        vector<int> curr(l2+1, 0);
        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        int maxi=-1e9;
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                // diagonal element
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1+prev[j-1];
                    maxi = max(maxi, curr[j]);
                }
                else curr[j]=0;
            }
            prev= curr;
        }
        return maxi;

}
