#include<bits/stdc++.h>

//refer- https://www.naukri.com/code360/problems/stocks-are-profitable_893405?interviewProblemRedirection=true&search=best%20time&attempt_status=COMPLETED

int maximumProfit(vector<int> &prices){
    int buy= prices[0];
    int profit= INT_MIN;

    for(int i=1; i<prices.size(); i++){
        int sell = prices[i]-buy;
        // cout<<sell<<" -> ";
        profit = max(profit, sell);
        buy = min(buy, prices[i]);
    }
    return profit > 0 ? profit: 0;
}