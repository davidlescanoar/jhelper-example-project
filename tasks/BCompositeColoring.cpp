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

ll gcd(ll a, ll b) { if(!b) return a; return gcd(b,a%b); }

void solve(istream& cin, ostream& cout)
{
    ll n, m=0;
    cin>>n;
    vector < ll > v(n),c(n,1);
    forn(i, n) cin>>v[i];
    forn(i, n)
    {
        if(v[i]==-1) continue;
        m++;
        forn(j, n)
        {
            if(i!=j&&v[j]!=-1)
            {
                ll g=gcd(v[i],v[j]);
                if(g>1)
                {
                    c[j]=m;
                    v[j]=-1;
                }
            }
        }
        v[i]=-1;
        c[i]=m;
    }
    cout<<m<<"\n";
    for(ll i:c) cout<<i<<" ";
    cout<<"\n";
}

void BCompositeColoring(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}