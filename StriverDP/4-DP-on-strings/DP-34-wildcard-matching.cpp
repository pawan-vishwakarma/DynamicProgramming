#include<bits/stdc++.h>

//refer- https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650?leftPanelTabValue=SUBMISSION


string s1, s2;

bool f(int i, int j, vector<vector<int>> &dp){
   // bases cases
   if(i < 0 and j<0) return true;

   if(i<0 and j>=0) return false;

   if(j<0 and i>=0){
      for(int ii=0; ii<s1.size(); ii++){
         if(s1[ii] != '*') return false;
         return true;
      }
   }

   if(dp[i][j] != -1) return dp[i][j];

   // recursive
   if(s1[i] == s2[j] or s1[i] == '?'){
      return dp[i][j]= f(i-1, j-1, dp);
   }

   if(s1[i] == '*'){
      return dp[i][j]= f(i, j-1, dp) or f(i-1, j, dp);
   }

   return dp[i][j]= false;
}


bool wildcardMatching(string pattern, string text)
{
   s1= pattern;
   s2= text;
   int l1= pattern.size();
   int l2= text.size();

      // vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
      // return f(pattern.size()-1, text.size()-1, dp);


      // vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
      // // base cases
      
      // for(int j=1; j<=l2; j++){
      //    dp[0][j]= 0;
      // } 

      // for(int i=1; i<=l1; i++){
      //    int flag=1;
      //    for(int ii=0; ii<=i; ii++){
      //       if(s1[ii] != '*') flag= 0;
      //       break;
      //    }
      //    dp[i][0]= flag;
      // }

      // dp[0][0]=1;
      // for(int i=1; i<=l1; i++){
      //    for(int j=1; j<=l2; j++){
      //       if(s1[i-1] == s2[j-1] or s1[i-1] == '?'){
      //          dp[i][j]= dp[i-1][j-1];
      //       }

      //       else if(s1[i-1] == '*'){
      //          dp[i][j]= dp[i][j-1] or dp[i-1][j];
      //       }
      //       else dp[i][j]= 0;
      //    }
      // }
      // return dp[l1][l2];

   // space optimsed
      // vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
      vector<int> prev(l2+1, 0), curr(l2+1, 0);
      // base cases
      
      prev[0]=1; // dp[0] means upper row or prev row
      for(int j=1; j<=l2; j++){
         prev[j]= 0;
      } 

      for(int i=1; i<=l1; i++){

         // assign the curr at every row
         int flag=1;
         for(int ii=1; ii<=i; ii++){
            if(s1[ii-1] != '*') {
               flag= 0;
               break;
            }
         }
         curr[0]= flag;
         //end of the test case

         for(int j=1; j<=l2; j++){
            if(s1[i-1] == s2[j-1] or s1[i-1] == '?'){
               curr[j]= prev[j-1];
            }
            else if(s1[i-1] == '*'){
               curr[j]= curr[j-1] or prev[j];
            }
            else curr[j]=0;
         }
         prev= curr;
      }
      return prev[l2];
}
