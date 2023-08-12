// recur and memo
#include<bits/stdc++.h>
typedef long long ll;
int mod = 1000000007;
int f(string&s ,int i, int j, int TrueOrFalse, vector<vector<vector<int>>>& dp)
{
    if(i>j) return 0;
    if(i==j) 
    {
        if(TrueOrFalse==1) return s[i]=='T';
        return s[i]=='F';
    }
    if(dp[i][j][TrueOrFalse]!=-1) return dp[i][j][TrueOrFalse];

    ll ans = 0;
    for(int k = i+1; k < j; k += 2) 
    {
        ll lt = f(s,i,k-1,1,dp);
        ll lf = f(s,i,k-1,0,dp);
        ll rt = f(s,k+1,j,1,dp);
        ll rf = f(s,k+1,j,0,dp);

        if (s[k] == '&') {
            if(TrueOrFalse==1) ans += lt * rt;
            else ans += lt * rf + rt * lf + lf*rf;
        } 

        else if (s[k] == '|') {
          if(TrueOrFalse==1) ans += lt * rt + lt * rf + rt * lf;
          else ans += lf*rf;
        } 
        else {
          if(TrueOrFalse==1) ans += lt * rf + rt * lf;
          else ans+= lt*rt + lf*rf;
        }
        ans = ans%mod;
    }
    return dp[i][j][TrueOrFalse] = ans;
}
int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return f(exp,0,n-1,1,dp);
}
// recur and memo

// tabulation
#include<bits/stdc++.h>
typedef long long ll;
int mod = 1000000007;

int evaluateExp(string & s) {
    int n=s.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    
    for(int i=0; i<n ; i++)
    {
        dp[i][i][1] = (s[i]=='T');
        dp[i][i][0] = (s[i]=='F');
    }

    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=i+1; j<n ; j++)
        {
            for(int TrueOrFalse=0 ; TrueOrFalse<=1; TrueOrFalse++)
            {
                ll ans = 0;
                for(int k = i+1; k < j; k += 2) 
                {
                    ll lt = dp[i][k-1][1];
                    ll lf = dp[i][k-1][0];
                    ll rt = dp[k+1][j][1];
                    ll rf = dp[k+1][j][0];

                    if (s[k] == '&') {
                        if(TrueOrFalse==1) ans += lt * rt;
                        else ans += lt * rf + rt * lf + lf*rf;
                    } 

                    else if (s[k] == '|') {
                    if(TrueOrFalse==1) ans += lt * rt + lt * rf + rt * lf;
                    else ans += lf*rf;
                    } else {
                    if (TrueOrFalse == 1)
                    ans += lt * rf + rt * lf;
                    else
                    ans += lt * rt + lf * rf;
                    }
                    ans = ans % mod;
                }
                dp[i][j][TrueOrFalse] = ans;
            }
        }
    }
    return dp[0][n-1][1];
}
// tabulation
