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
    ll n, k;
    cin>>n>>k;
    multiset < pair < ll, ll > > z;
    forn(i, n)
    {
        ll inp;
        cin>>inp;
        z.insert({inp*inp,inp});
    }
    while(sz(z)<k)
    {
        auto it=prev(z.end());
        pair < ll, ll > v=*it;
        z.erase(it);
        ll a=v.se/2;
        ll b=v.se-a;
        z.insert({a*a,a});
        z.insert({b*b,b});
    }
    ll r=0;
    for(auto i:z) r+=i.fi;
    cout<<r<<"\n";
}

void ECarrotsForRabbits(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}