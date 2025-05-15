#include<bits/stdc++.h>
// refer- https://www.naukri.com/code360/problems/frog-jump_3621012
// Top down DP
int f(int i , vector<int> &h ,vector<int> &dp){
	
    if(i == 0)
        return 0 ;
    
    if(dp[i] != -1)
        return dp[i] ;
    
    int op2;
    int op1 = f(i-1,h,dp)+abs(h[i] -h[i-1]) ;
    if(i>1)
    	op2 = f(i-2,h,dp)+abs(h[i] -h[i-2]) ;
    else
        op2 = INT_MAX ;
    
    return dp[i] = min(op1,op2) ;
    
}


int frogJump(int n, vector<int> &heights)
{
    
    // Bottom up dp
    vector<int> dp(n+1,-1) ;
    
    dp[0] = 0 ;
    if(n == 1)
        return 0 ;
    int prev2 = 0 ;
    int prev = 0 ;
    int curr ;
    
    for(int i=1;i<n;i++){
        int op1 = prev + abs(heights[i] -heights[i-1]) ;
        int op2 ;
        if(i>1)
        	op2 = prev2 + abs(heights[i] -heights[i-2]) ;
        else
            op2 = INT_MAX ;
        curr = min(op1,op2) ;
        prev2 = prev ;
        prev = curr ;
    }
    
    return prev ;
    


}