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
    multiset < ll > ms;
    fore(i, 1, n) ms.insert(i);
    vector < vector < ll > > pasos;
    while(sz(ms)>1)
    {
        ll s=0;
        vector < ll > p;
        forn(i,2)
        {
            ll v=*prev(ms.end());
            s+=v;
            p.push_back(v);
            ms.erase(prev(ms.end()));
        }
        pasos.push_back(p);
        s=ceil(s/2.0);
        ms.insert(s);
    }
    cout<<*ms.begin()<<"\n";
    for(auto i:pasos) cout<<i[1]<<" "<<i[0]<<"\n";
}

void CNumbersOnWhiteboard(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}