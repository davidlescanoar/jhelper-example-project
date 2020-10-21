#include <bits/stdc++.h>

typedef long long ll;
const int INFI=(1<<29);
const ll INFL=(1LL<<60);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) int(x.size())
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define forn(tourBina,n) for(ll tourBina=0;tourBina<n;tourBina++)
#define fore(tourBina,l,r) for(ll tourBina=l;tourBina<=r;tourBina++)
#define DBG(x) cerr<<#x<<" = "<<x<< endl

using namespace std;

ll DP(const string &s, vector < vector < ll > > &dp, ll p, ll t)
{
    if(p==sz(s)) return 0;
    if(dp[p][t]<INFL) return dp[p][t];
    if(t==0)
    {
        dp[p][t]=min(dp[p][t],DP(s,dp,p+1,1)+(s[p]=='0'));
        dp[p][t]=min(dp[p][t],DP(s,dp,p+1,0)+(s[p]=='1'));
    }
    if(t==1)
    {
        dp[p][t]=min(dp[p][t],DP(s,dp,p+1,1)+(s[p]=='0'));
        dp[p][t]=min(dp[p][t],DP(s,dp,p+1,2)+(s[p]=='1'));
    }
    if(t==2)
    {
        dp[p][t]=min(dp[p][t],DP(s,dp,p+1,2)+(s[p]=='1'));
    }
    return dp[p][t];
}

void solve(istream& cin, ostream& cout)
{
    ll n, k,r=INFL, u=0;
    string s;
    cin>>n>>k>>s;
    vector < string > p(k);
    forn(i, n) p[i%k]+=s[i], u+=(s[i]=='1');
    forn(i, k)
    {
        vector < vector < ll > > dp(sz(p[i])+1,vector < ll >(3,INFL));
        r=min(r,(DP(p[i],dp,0,0)+(u-count(all(p[i]),'1'))));
    }
    cout<<min(r,u)<<"\n";
}

void EKPeriodicGarland(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}