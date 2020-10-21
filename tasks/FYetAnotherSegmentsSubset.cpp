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

void solve(istream& cin, ostream& cout)
{
    int n;
    cin>>n;
    vector < pair < int, int > > v(n);
    vector < vector < int > > R, dp;
    vector < int > elem;
    forn(i,n)
    {
        cin>>v[i].fi>>v[i].se;
        elem.push_back(v[i].fi);
        elem.push_back(v[i].se);
    }
    sort(all(elem));
    unique(all(elem));
    R.resize(sz(elem)+10);
    for(auto &i:v)
    {
        int a=lower_bound(all(elem),i.fi)-elem.begin();
        int b=lower_bound(all(elem),i.se)-elem.begin();
        i={a,b};
        R[i.fi].push_back(i.se);
    }
    dp=vector < vector < int > >(sz(elem)+10, vector < int >(sz(elem)+10,-1));
    for(ll l=sz(elem)-1;l>=0;l--)
    {
        for(ll r=l;r<=sz(elem)-1;r++)
        {
            bool seg=count(all(R[l]),r);
            dp[l][r]=seg;
            if(l+1<=r) dp[l][r]=dp[l+1][r]+seg;
            for(ll i:R[l])
            {
                if(i>=r) continue;
                if(i+1<=r) dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]+seg);
                else dp[l][r]=max(dp[l][r],dp[l][i]+seg);
            }
        }
    }
    ll maxx=0;
    forn(i, sz(elem)+10) maxx=max(maxx,(ll)*max_element(all(dp[i])));
    cout<<maxx<<"\n";
}

void FYetAnotherSegmentsSubset(istream& in, ostream& out)
{
    int casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}