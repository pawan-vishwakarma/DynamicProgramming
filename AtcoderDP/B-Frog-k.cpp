// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &arr, vector<int> &dp){
    if(n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    
    dp[n] = INT_MAX;
    for(int j=1; j<=k ; j++){
        if(n-j >= 0){
            int curr = abs(arr[n]-arr[n-j])+solve(n-j, k, arr, dp);
            dp[n] = min(curr, dp[n]);
        }
    }
    
    return dp[n];
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr;    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> dp(n+1, -1);
    int ans = solve(n-1, k, arr, dp);
    cout<<ans<<endl;
    return 0;
}