// memo
class Solution {
public:
    bool isPalindrome(string&s, int i, int j)
    {
        for(int k=i ; k<=j ; k++)
        {
            if(s[k] != s[j-k+i]) return false;
        }
        return true;
    }
    int f(string& s, int i,vector<int>& dp)
    {
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        string temp;
        for(int j=i ; j<s.size() ; j++)
        {
            temp+= s[j];
            if( isPalindrome(s,i,j)) ans = min(ans,1+f(s,j+1,dp));
        }
        return dp[i] = ans;

    }
    int minCut(string s) 
    {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(s,0,dp)-1;
    }
};
// memo

//tabulation
bool isPalindrome(string&s, int i, int j)
{
    for(int k=i ; k<=j ; k++)
    {
        if(s[k] != s[j-k+i]) return false;
    }
    return true;
}
int palindromePartitioning(string s)
{
    int n=s.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            int ans = INT_MAX;
            for(int j=i ; j<n ; j++)
            {
                if( isPalindrome(s,i,j)) ans = min(ans,1+dp[j+1]);
            }
            dp[i] = ans;
        }
        return dp[0]-1;
}

// tabulation
