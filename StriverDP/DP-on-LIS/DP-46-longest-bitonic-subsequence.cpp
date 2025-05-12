// refer - https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=SUBMISSION

vector<int> lis(vector<int>& arr, int n){

	vector<int> dp(n+1, 1);
	for(int ind=0; ind<n; ind++){
		for(int j=0; j<ind; j++){
			if(arr[ind] > arr[j] && dp[ind] < 1+dp[j]){
				dp[ind]= 1+dp[j];
			}
		}
	}
	return dp;
}

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// starting from 0 generate lis array
	vector<int> dp(n+1, 1);
	for(int ind=0; ind<n; ind++){
		for(int j=0; j<ind; j++){
			if(arr[ind] > arr[j] && dp[ind] < 1+dp[j]){
				dp[ind]= 1+dp[j];
			}
		}
	}

	// starting from generating lis array
	vector<int> dp1(n+1, 1);
	for(int ind=n-1; ind>=0; ind--){
		for(int j=n-1; j>ind; j--){
			if(arr[ind] > arr[j] && dp1[ind] < 1+dp1[j]){
				dp1[ind]= 1+dp1[j];
			}
		}
	}
	
	int ans=0;
	// max of sum -1 is ans
	for(int i=0; i<n; i++){
		int sum= dp[i]+dp1[i]-1;
		ans= max(ans, sum);
	}
	return ans;
}
