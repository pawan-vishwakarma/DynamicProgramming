#include <bits/stdc++.h> 

// refer- https://www.naukri.com/code360/problems/shortest-supersequence_4244493


string shortestSupersequence(string s1, string s2)
{

	int l1 = s1.size();
	int l2 = s2.size();

	// create a table for lcs

	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

	for(int i=1; i<=l1; i++){
		for(int j=1; j<=l2; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	// cout<<dp[l1][l2]<<endl;

	// printing the common supersequence -- make table for better understanding
	int i= l1, j= l2;
	string ans="";


	while(i>0 and j>0){
		if(s1[i-1] == s2[j-1]){
			ans += s1[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){ // moving up so picking s1's left out char 
			ans += s1[i-1];
			i--;
		}
		else{
			ans += s2[j-1];
			j--;
		}
	}
	// for remaining chars in s1
	while(i>0){
		ans += s1[i-1];
		i--;
	}

	// for remaining chars in s2
	while(j>0){
		ans += s2[j-1];
		j--;
	}
	// always remember to reverse
	reverse(ans.begin(), ans.end());
	// cout<<ans<<endl;
	return ans;
	
}
