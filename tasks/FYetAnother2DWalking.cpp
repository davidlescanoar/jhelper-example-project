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

const ll MAXN=(ll)2e5+10;

ll dp[MAXN][2];

ll DP(ll p, ll x, ll y)
{
    if(dp[x][y])
}

void solve(istream& cin, ostream& cout)
{
    ll n;
    cin>>n;
    vector < pair < ll, ll > > v(n);
    map < ll, pair < ll, ll > > m1,m2;
    map < ll, ll > nivel;
    forn(i, n) cin>>v[i].fi>>v[i].se;
    sort(all(v),[](const pair < ll, ll > &a, const pair < ll, ll > &b)
    {
        if(max(a.fi,a.se)!=max(b.fi,b.se)) return max(a.fi,a.se)<max(b.fi,b.se);
        return a<b;
    });
    for(pair < ll, ll > i:v) if(m1.find(max(i.fi,i.se))==m1.end()) m1[max(i.fi,i.se)]=i;
    for(pair < ll, ll > i:v) m2[max(i.fi,i.se)]=i;
    for(auto i:m1) nivel[i.fi]=abs(i.se.fi-m2[i.fi].fi)+abs(i.se.se-m2[i.fi].se);
    for(auto i:nivel) cout<<i.fi<<" "<<i.se<<"\n";
    cout<<DP(0,0,0)<<"\n";
}

void FYetAnother2DWalking(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}