// recur and memo
class Solution {
public:
    int f(vector<int> &nums, int i, int j,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        int ans = INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i ; k<=j ; k++)
        {
            int points = nums[i-1]*nums[j+1]*nums[k] + f(nums,i,k-1,dp)+f(nums,k+1,j,dp);
            ans = max(ans,points);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(nums,1,n,dp);
    }
};
// recur and memo

// tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int i=n ; i>=1 ; i--)
        {
            for(int j=i ; j<=n ; j++)
            {
                int ans = INT_MIN;
                for(int k=i ; k<=j ; k++)
                {
                    int points = nums[i-1]*nums[j+1]*nums[k] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans,points);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};
// tabulation
