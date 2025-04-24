#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    fast_io;
    string s;
    getline(cin, s);
    
    stack<int> st;
    vector<int> dp(s.size(), 0);
    int maxi = 0;
    int count = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        } else if(s[i] == ')' && !st.empty()) {
            int top = st.top();
            st.pop();
            
            dp[i] = i - top + 1 + (top > 0 ? dp[top - 1] : 0); // dp[top-1] stores previous regular exp len
            if(dp[i] > maxi) {
                maxi = dp[i];
                count = 1;
            } else if(dp[i] == maxi) {
                count++;
            }
        }
    }
    
    if(count == 0) count =1;
    
    cout << maxi << " " << count << endl;
    return 0;
}
