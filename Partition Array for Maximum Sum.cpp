// memo
class Solution {
public:
    int f(vector<int>& arr, int k, int i,vector<int>&dp)
    {
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MIN;
        int maxi = 0;
        for(int j=i ; j<=i+k-1 && j<arr.size(); j++)
        {
            maxi = max(maxi,arr[j]);
            ans = max(ans,(j-i+1)*maxi + f(arr,k,j+1,dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(arr,k,0,dp);
    }
};
// memo

// tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            int ans = INT_MIN;
            int maxi = 0;
            for(int j=i ; j<=i+k-1 && j<arr.size(); j++)
            {
                maxi = max(maxi,arr[j]);
                ans = max(ans,(j-i+1)*maxi + dp[j+1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
// tabulation
