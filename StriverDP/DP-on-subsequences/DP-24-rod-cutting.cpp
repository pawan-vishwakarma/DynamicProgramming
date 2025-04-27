#include<bits/stdc++.h>

int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp){

	if(ind == 0){
		// here at 0th ind rodlen will be 1 and to get size rod we require n rods with price[0] cost
		return n*price[0];
	}

	if(dp[ind][n] != -1) return dp[ind][n];

	int nottake = f(ind-1, n, price, dp);
	// ind+1 is the len of rod with price[ind]
	int rodlen = ind+1;
	int take = -1e9;

	// always remember -- infinite choice we dont decrese ind
	if(rodlen <= n){
		take = price[ind]+f(ind, n-rodlen, price, dp);
	}

	return dp[ind][n] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{

		// vector<vector<int>> dp(n, vector<int>(n+1, -1));
		// return f(n-1, n ,price, dp);

		// vector<vector<int>> dp(n, vector<int>(n+1, -1));
		// for(int i=0; i<=n; i++){
		// 	dp[0][i] = i*price[0] ;
		// }

		// for(int i=1; i<n;i++){
		// 	for(int j=0; j<=n ;j++){
		// 		int nottake = dp[i-1][j];
		// 		// ind+1 is the len of rod with price[ind]
		// 		int rodlen = i+1;
		// 		int take = -1e9;

		// 		// always remember -- infinite choice we dont decrese ind
		// 		if(rodlen <= j){
		// 			take = price[i]+dp[i][j-rodlen];
		// 		}

		// 		dp[i][j] = max(take, nottake);
		// 	}
		// }
		// return dp[n-1][n];

	// space optimised
		// vector<vector<int>> dp(n, vector<int>(n+1, -1));
		vector<int> prev(n+1, 0), curr(n+1, 0);

		for(int i=0; i<=n; i++){
			prev[i] = i*price[0] ;
		}

		for(int i=1; i<n;i++){
			for(int j=0; j<=n ;j++){
				int nottake = prev[j];
				// ind+1 is the len of rod with price[ind]
				int rodlen = i+1;
				int take = -1e9;

				// always remember -- infinite choice we dont decrese ind
				if(rodlen <= j){
					take = price[i]+curr[j-rodlen];
				}

				curr[j] = max(take, nottake);
			}
			prev =curr;
		}
		return prev[n];
}
