// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr, vector<int> &dp){
    if(n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    
    int op2 = INT_MAX;
    int op1 = abs(arr[n]-arr[n-1])+solve(n-1, arr, dp);
    if(n > 1){
        op2 = abs(arr[n]-arr[n-2])+solve(n-2, arr, dp);
    }
    
    
    return dp[n] = min(op1, op2);
}
int main() {
    int n;
    cin>>n;
    vector<int> arr;    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> dp(n+1, -1);
    int ans = solve(n-1, arr, dp);
    cout<<ans<<endl;
    return 0;
}
