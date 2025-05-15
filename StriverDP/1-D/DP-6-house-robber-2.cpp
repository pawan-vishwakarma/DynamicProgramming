#include <bits/stdc++.h> 
//refer- https://www.naukri.com/code360/problems/house-robber_839733
long long int solve(vector<int> arr){
    long long int prev2=0;
    long long int prev=arr[0];

    for(int i=1; i<arr.size(); i++){
        long long int pick = arr[i]+prev2;

        long long int non = prev;

        long long int curr = max(pick, non);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int> temp1, temp2;
    int n=valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]); 
    }

    return max(solve(temp1), solve(temp2));
}