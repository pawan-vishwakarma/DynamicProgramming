 // https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980?leftPanelTabValue=SUBMISSION

 #include<bits/stdc++.h>


bool solve(int n, int k, vector<int> &arr, vector<vector<bool>> &dp){

	if(k == 0) return true;

	if(n == 0) return arr[0] == k;

	if(dp[n][k] != 0) return dp[n][k];

	bool nonpick = solve(n-1, k, arr, dp);
	bool pick = false;

	if(arr[n] <= k)
		pick = solve(n-1, k-arr[n], arr, dp);

	dp[n][k] = pick | nonpick;
	return dp[n][k];

}



bool canPartition(vector<int> &arr, int n)
{
	int sum = accumulate(arr.begin(), arr.end(), 0);

	if(sum%2) return false;
	vector<vector<bool>>dp(n, vector<bool>(sum, 0));


		int k = sum/2;

		vector<bool> prev(k+1, 0);
        vector<bool> curr(k+1, 0);

        prev[0] = curr[0] =true;
        prev[arr[0]]=true;

        for(int i=0;i<n;i++){
            dp[i][0] = true ;
        }

        for(int i=1;i<n;i++){
            for(int j=1; j<=k; j++){

                bool nonpick = prev[j];
                bool pick= false;

                if(arr[i] <= j)
                    pick = prev[j-arr[i]];

                curr[j] = pick | nonpick;
                // cout<<dp[i][j]<<" ";
                
            }
            // cout<<endl;
            prev = curr;
        }

        return prev[k];
}
