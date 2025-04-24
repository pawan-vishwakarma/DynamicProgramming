#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
char _;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string findLCS(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string ans="";
    //Regenrate the lcs string
    int i=m, j=n;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else{
            j--;
        }
    }
    // cout<< ans << endl;
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}


int main() {
    string s1, s2;
    // cout << "Enter first string: ";
    cin >> s1;
    // cout << "Enter second string: ";
    cin >> s2;

    string lcs = findLCS(s1, s2);
    cout  << lcs << endl;

    return 0;
}
