#include<bits/stdc++.h>

//refer- https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=SUBMISSION

int mod = 1000000007;


int f(int i, int j, int istrue, string &exp, vector<vector<vector<long long>>> &dp){
    if(i> j) return 0;

    if(i == j){
        if(istrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }

    if(dp[i][j][istrue] != -1)return dp[i][j][istrue];

    long long ways= 0;
    for(int ind= i+1; ind<=j-1; ind+=2){

        long long lT= f(i, ind-1, 1, exp, dp);
        long long lF= f(i, ind-1, 0, exp, dp);
        long long rT= f(ind+1, j, 1, exp, dp);
        long long rF= f(ind+1, j, 0, exp, dp);

        if(exp[ind] == '&'){
            if(istrue){
                ways= (ways+ (lT*rT)%mod)%mod;
            }
            else{
                ways= (ways+ (lF*rT)%mod+ (lT*rF)%mod+ (lF*rF)%mod)%mod;
            }
        }
        else if(exp[ind] == '|'){
            if(istrue){
                ways= (ways+ (lT*rT)%mod+ (lT*rF)%mod+ (lF*rT)%mod)%mod;
            }
            else{
                ways= (ways+ (lF*rF)%mod)%mod;
            }
        }
        else{
            // xor T^T=F F^F=F T^F=T F^T=T
            if(istrue){
                ways= (ways+ (lT*rF)%mod+ (lF*rT)%mod)%mod;
            }
            else{
                ways= (ways+ (lT*rT)%mod+ (lF*rF)%mod)%mod;
            }
        }
    }
    return dp[i][j][istrue]= ways%mod;
}

int evaluateExp(string & exp) {
    int n= exp.length();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0,n-1, 1, exp, dp);
}