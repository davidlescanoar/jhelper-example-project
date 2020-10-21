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

ll f(vector < ll > v, ll a, ll b){ for(ll i:v) if(i!=a&&i!=b) return i; }

void solve(istream& cin, ostream& cout)
{
    ll n, prev=-1;
    cin>>n;
    vector < ll > a(n), b(n), c(n), r(n);
    forn(i, n) cin>>a[i];
    forn(i, n) cin>>b[i];
    forn(i, n) cin>>c[i];
    forn(i, n) prev=r[i]=f({a[i],b[i],c[i]},prev,(i==n-1?r[0]:prev));
    for(ll i:r) cout<<i<<" ";
    cout<<"\n";
}

void ACircleColoring(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}