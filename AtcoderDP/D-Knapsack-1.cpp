#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, w;
    cin >> n >> w;
    vector<long long> wt(n, 0);
    vector<long long> val(n, 0);
    
    for(int i = 0; i < n; i++){
        cin >> wt[i];
        cin >> val[i];
    }
    
    vector<vector<long long>> dp(n+1, vector<long long>(w+1, 0));
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    
    long long ans = dp[n][w];
    cout << ans << endl;
    return 0;
}
