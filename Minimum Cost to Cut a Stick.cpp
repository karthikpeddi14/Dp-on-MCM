// recur and memo my method
class Solution {
public:
    int f(vector<int>& cuts, int i, int j,vector<vector<int>>& dp)
    {
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        int flag= 0;
        for(int k=0 ; k<cuts.size() ; k++)
        {
            if(i<cuts[k] && cuts[k]<j)
            {
                flag++;
                ans = min(ans,f(cuts,i,cuts[k],dp)+f(cuts,cuts[k],j,dp)+j-i);
            }
        }
        if(flag==0) return dp[i][j] = flag;
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(cuts,0,n,dp);
    }
};
// recur and memo

// tabulation my method
class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        sort(cuts.begin(),cuts.end());

        for(int i=n-1; i>=0 ; i--)
        {
            for(int j=i+2 ; j<=n ; j++)
            {
                int ans = 1e9;
                int flag= 0;
                for(int k=cuts.size()-1 ; k>=0 ; k--)
                {
                    if(i<cuts[k] && cuts[k]<j)
                    {
                        flag++;
                        ans = min(ans,dp[i][cuts[k]]+dp[cuts[k]][j] + j-i);
                    }
                    else if(cuts[k]<=i) break;
                }
                if(flag==0) dp[i][j] = flag;
                else dp[i][j] = ans;
            }
        }
        return dp[0][n];
    }
};
// tabulation my method

// striver memo
class Solution {
public:
    int f(vector<int>& cuts, int i, int j,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        int ans = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i ; k<=j ; k++)
        {
            int cost =  f(cuts,i,k-1,dp) + f(cuts,k+1,j,dp) + cuts[j+1]-cuts[i-1];
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return f(cuts,1,c,dp);
    }
};
// striver memo

// tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        
        for(int i=c ; i>=1 ; i--)
        {
            for(int j=i; j<=c; j++)
            {
                int ans = 1e9;
                for(int k=i ; k<=j ; k++)
                {
                    int cost =  dp[i][k-1] + dp[k+1][j] + cuts[j+1]-cuts[i-1];
                    ans = min(ans,cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][c];
    }
};
// tabulation
