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
    ll n, m,r=0;
    cin>>n>>m;
    vector < vector < ll > > v(n, vector < ll >(m));
    forn(i, n) forn(j, m) cin>>v[i][j];
    for(ll i=0,i2=n-1; i<=i2; i++,i2--)
    {
        for(ll j=0,j2=m-1; j<=j2; j++,j2--)
        {
            vector < ll > vv={v[i][j],v[i][j2],v[i2][j],v[i2][j2]};
            vector < pair < ll, ll > > vvv={{i,j},{i,j2},{i2,j},{i2,j2}};
            sort(all(vv));
            ll e=vv[1];
            forn(x, sz(vvv)) r+=abs(e-v[vvv[x].fi][vvv[x].se]), v[vvv[x].fi][vvv[x].se]=e;
        }
    }
    cout<<r<<"\n";
}

void BNiceMatrix(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}