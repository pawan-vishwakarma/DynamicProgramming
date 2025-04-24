// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(3,0));    
    for(int i=0;i<n;i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    
    // int ans =0 ;
    vector<vector<int>> dp(n, vector<int>(3,-1));
    
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    
    for(int i=1; i<n ;i++){
        for(int j=0; j<3; j++){
            for(int jj =0; jj<3; jj++){
                if(jj != j){
                    int temp = dp[i-1][jj]+arr[i][j];
                    dp[i][j] = max(temp,dp[i][j]);
                }
            }
            
        }
        
    }
    int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    
    cout<<ans<<endl;
    return 0;
}