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
    vector < ll > v(3);
    forn(i, 3) cin>>v[i];
    sort(all(v));
    pair < ll, ll > a={0,v[0]};
    pair < ll, ll > b={v[2],v[1]};
    ll r=sqrt(((a.fi-b.fi)*(a.fi-b.fi))+((a.se-b.se)*(a.se-b.se)));
    cout<<r<<"\n";
}

void AFence(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}