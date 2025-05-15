#include <bits/stdc++.h> 

// REFER -https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTabValue=SUBMISSION

int minimumElements(vector<int> &coins, int p)
{
    int n =coins.size();
    
    vector<int> prev(p+1, 0), curr(p+1, 0);

    for(int t= 0; t<= p; t++){
        if(t%coins[0] == 0){
            prev[t] = t/coins[0];
        }
        else{
            prev[t] = 1e9;
        }
    }

    // loops as per changing params
    for(int i=1; i<n; i++){
        for(int j=0; j<= p; j++){

            int notpick = prev[j]; 
            //pick
            int pick = 1e9;
            if(coins[i] <= j){
                pick = 1+curr[j-coins[i]];
            }

            curr[j] = min(pick, notpick);
        }
        prev = curr;
    }
    if(prev[p] >= 1e9) return -1;
    return prev[p];
}