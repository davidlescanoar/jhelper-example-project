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
    ll n;
    cin>>n;
    vector < ll > v(n);
    forn(i, n) cin>>v[i];
    vector < ll > v1, v2;
    forn(i, n)
    {
        if(i%2) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    ll u=min(count(all(v1),1), count(all(v2),1))*2;
    vector < ll > r;
    forn(i,n)
    {
        if(!v[i])
            r.push_back(v[i]);
        else if(u)
            u--,r.push_back(v[i]);
    }
    cout<<sz(r)<<"\n";
    for(ll i:r) cout<<i<<" ";
    cout<<"\n";
}

void AAhahahahahahahaha(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}