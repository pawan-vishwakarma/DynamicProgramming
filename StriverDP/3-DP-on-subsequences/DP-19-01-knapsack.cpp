#include<bits/stdc++.h>
// REFER - https://www.naukri.com/code360/problems/0-1-knapsack_1072980?interviewProblemRedirection=true&search=0%2F1&leftPanelTabValue=SUBMISSION


// maximising values here -- returning values
int f(int ind, int w, vector<int>& weights, 
		vector<int> &values, vector<vector<int>> &dp){

	// at 0th ind-- base case
	if(ind == 0){
		if(weights[0] <= w){
			return values[0];
		}
		else{
			return 0;
		}
	} 

	if(dp[ind][w] != 0) return dp[ind][w];

	// recursive
	int notpick = 0+f(ind-1, w, weights, values, dp);
	int pick = INT_MIN;

	if(weights[ind] <= w){
		pick = values[ind]+f(ind-1, w-weights[ind], weights, values, dp);
	}

	return dp[ind][w]= max(pick, notpick);

}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
// memoistaion+recursion
	// vector<vector<int>> dp(n, vector<int>(w+1,0));
	// return f(n-1, w, weights, values, dp);


// Tabulation
	vector<vector<int>> dp(n, vector<int>(w+1,0));
	for(int i= weights[0]; i<=w; i++){
		dp[0][i]=values[0];
		// cout<<dp[0][i]<<" ";
	}

	for(int i=1; i<n; i++){
		for(int j=0; j<=w; j++){
			int nonpick = dp[i-1][j];
			int pick = INT_MIN;
			if(weights[i] <= j){
				pick = values[i]+dp[i-1][j-weights[i]];
			}
			dp[i][j] = max(nonpick, pick);
		}
	}

	// return dp[n-1][w];

// space-optimised
	// vector<int> prev(w+1, 0), curr(w+1, 0);
	// for(int i= weights[0]; i<=w; i++){
	// 	prev[i]=values[0];
	// 	// cout<<dp[0][i]<<" ";
	// }

	// for(int i=1; i<n; i++){
	// 	for(int j=0; j<=w; j++){
	// 		int nonpick = prev[j];
	// 		int pick = INT_MIN;
	// 		if(weights[i] <= j){
	// 			pick = values[i]+prev[j-weights[i]];
	// 		}
	// 		curr[j] = max(nonpick, pick);
	// 	}
	// 	prev = curr;
	// }

	// return prev[w];

// single row space
	vector<int> prev(w+1, 0);
	for(int i= weights[0]; i<=w; i++){
		prev[i]=values[0];
		// cout<<dp[0][i]<<" ";
	}

	for(int i=1; i<n; i++){
		for(int j=w; j>=0; j--){
			int nonpick = prev[j];
			int pick = INT_MIN;
			if(weights[i] <= j){
				pick = values[i]+prev[j-weights[i]];
			}
			prev[j] = max(nonpick, pick);
		}
		// prev = curr;
	}

	return prev[w];


}