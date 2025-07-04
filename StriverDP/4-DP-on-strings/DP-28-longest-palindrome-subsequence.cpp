#include <bits/stdc++.h> 

// REFER- https://www.naukri.com/code360/problems/longest-palindromic-subsequence_842787?interviewProblemRedirection=true&search=longest%20pali&attempt_status=COMPLETED
int lcs(string &s1, string &s2){
    // s1 = str1;
    // s2 = str2;
	int l1 = s1.size();
	int l2 = s2.size();
	// memo+recurs
		// vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
		// return f(s1.size()-1, s2.size()-1, dp);

	// Tabulation
		// vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

		// for(int i=1; i<=l1; i++){
		// 	for(int j=1; j<=l2; j++){
		// 		if(s1[i-1] == s2[j-1]){
		// 			dp[i][j] = 1+dp[i-1][j-1];
		// 		}
		// 		else{
		// 			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		// 		}
		// 	}
		// }
		// return dp[l1][l2];

	// space-optimissed
		vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

		vector<int> prev(l2+1, 0);
		vector<int> curr(l2+1, 0);

		for(int i=1; i<=l1; i++){
			for(int j=1; j<=l2; j++){
				if(s1[i-1] == s2[j-1]){
					curr[j] = 1+prev[j-1];
				}
				else{
					curr[j] = max(prev[j], curr[j-1]);
				}
			}
			prev= curr;
		}
		return prev[l2];

}


int longestPalindromeSubsequence(string s)
{
   string s2 = s;
   reverse(s.begin(), s.end());
   return lcs(s, s2);
}
