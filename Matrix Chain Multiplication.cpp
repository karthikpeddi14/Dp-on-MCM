// recur and memo
include <bits/stdc++.h>
int f(int* arr, int i,  int j,vector<vector<int>>& dp)
{
     if(i+1==j) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int ans = INT_MAX;
     for(int k=i+1; k<j ; k++){
        ans = min(ans,f(arr,i,k,dp)+f(arr,k,j,dp)+arr[i]*arr[k]*arr[j]);
        }
     return dp[i][j]=ans;
    
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(arr,0,n,dp);
}
// recur and memo

// tabulation
#include <bits/stdc++.h>
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int i=n-1 ; i>=0; i--)
    {
        for(int j=i+2 ; j<=n ; j++)
        {
            int ans = INT_MAX;
            for(int k=i+1; k<j ; k++){
                ans = min(ans,dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n];
}
// tabulation
