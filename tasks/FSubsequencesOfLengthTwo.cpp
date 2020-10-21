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

const ll MAXN=210;

ll dp[MAXN][MAXN];

void solve(istream& cin, ostream& cout)
{
    ll n, lim;
    string s, t;
    cin>>n>>lim>>s>>t;
    forn(j,MAXN) forn(k,MAXN) dp[j][k]=-INFL;
    dp[0][0]=0;
    forn(i, n)
    {
        for(ll j=lim;j>=0;j--)
        {
            for(ll k=n;k>=0;k--)
            {
                if(dp[j][k]==-INFL) continue;
                if(t[0]==t[1])
                {
                    if(s[i]==t[0])
                    {
                        dp[j][k+1]=max(dp[j][k+1],dp[j][k]+k);
                    }
                    else
                    {
                        dp[j+1][k+1]=max(dp[j+1][k+1],dp[j][k]+k);
                    }
                }
                else
                {
                    if(s[i]==t[0])
                    {
                        dp[j][k+1]=max(dp[j][k+1],dp[j][k]);
                        dp[j+1][k]=max(dp[j+1][k],dp[j][k]+k);
                    }
                    if(s[i]==t[1])
                    {
                        dp[j][k]=max(dp[j][k],dp[j][k]+k);
                        dp[j+1][k+1]=max(dp[j+1][k+1],dp[j][k]);
                    }
                    if(s[i]!=t[0]&&s[i]!=t[1])
                    {
                        dp[j+1][k+1]=max(dp[j+1][k+1],dp[j][k]);
                        dp[j+1][k]=max(dp[j+1][k],dp[j][k]+k);
                    }
                }
            }
        }
    }
    ll maxx=0;
    fore(j,0,lim) fore(k,0,n) maxx=max(maxx,dp[j][k]);
    cout<<maxx<<"\n";
}

void FSubsequencesOfLengthTwo(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}