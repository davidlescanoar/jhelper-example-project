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
    vector < bool > uA(110, false), uB(110, false);
    forn(i, n) cin>>v[i];
    sort(all(v));
    vector < ll > A, B;
    forn(i, n)
    {
        if(uA[v[i]])
            uB[v[i]]=1;
        else
            uA[v[i]]=1;
    }
    ll s=0;
    fore(i, 0, 109) if(!uA[i]){ s+=i; break; }
    fore(i, 0, 109) if(!uB[i]){ s+=i; break; }
    cout<<(ll)s<<"\n";
}

void ASubsetMex(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}