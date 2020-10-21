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

ll sol(ll a,ll b,ll x,ll y,ll n)
{
    ll ca=(a-max(x,a-n));
    n-=ca;
    a-=ca;
    ll cb=(b-max(y,b-n));
    n-=cb;
    b-=cb;
    return (ll)(a*b);
}

void solve(istream& cin, ostream& cout)
{
    ll a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    ll s1=sol(a,b,x,y,n);
    ll s2=sol(b,a,y,x,n);
    cout<<(ll)min(s1,s2)<<"\n";
}

void BMinimumProduct(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}