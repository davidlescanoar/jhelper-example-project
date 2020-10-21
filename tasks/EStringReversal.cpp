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

const ll MAXN=(ll)2e5+10;
ll ft[MAXN];
void upd(ll x){for(ll i=x;i<MAXN;i+=(i&-i)) ft[i]++;}
ll get(ll x){ll s=0; for(ll i=x;i;i-=(i&-i)) s+=ft[i]; return s;}

void solve(istream& cin, ostream& cout)
{
    memset(ft,0,sizeof(ft));
    ll n,r=0;
    string s;
    cin>>n>>s;
    s=" "+s;
    vector < vector < ll > > l(26);
    fore(i,1,n) l[s[i]-'a'].push_back(i);
    for(ll i=1,j=n;i<=n;i++,j--)
    {
        ll pos=l[s[i]-'a'].back();
        l[s[i]-'a'].pop_back();
        upd(pos);
        pos-=get(pos-1);
        r+=(j-pos);
    }
    cout<<r<<"\n";
}

void EStringReversal(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}