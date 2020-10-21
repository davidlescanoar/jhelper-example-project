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

ll n,q;
vector < ll > st;

void update(ll p, ll val)
{
    p+=n;
    st[p]=val;
    p/=2;
    while(p)
    {
        st[p]=st[p*2]+st[p*2+1];
        p/=2;
    }
}

ll get(ll p, ll L, ll R, ll i, ll j)
{
    if(L>j||R<i) return 0LL;
    if(L>=i&&R<=j) return st[p];
    return (ll)(get(p*2,L,(L+R)/2,i,j)+get(p*2+1,(L+R)/2+1,R,i,j));
}

void solve(istream& cin, ostream& cout)
{
    cin>>n>>q;
    st=vector < ll >(n*4+10,0);
    forn(i, n) cin>>st[n+i];
    for(ll i=n-1;i>0;i--) st[i]=st[i*2]+st[i*2+1];
    while(q--)
    {
        ll t, a, b;
        cin>>t>>a>>b;
        if(t==1)
        {
            update(a-1,b);
        }
        else
        {
            cout<<(ll)get(1,0,n-1,a-1,b-1)<<"\n";
        }
    }
}

void RangeSumQueriesII(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}