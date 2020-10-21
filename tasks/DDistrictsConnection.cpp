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
    if(count(all(v),v[0])==n){cout<<"NO\n";return;}
    cout<<"YES\n";
    map < ll, ll > mapa;
    forn(i, n) mapa[v[i]]++;
    pair < ll, ll > minn={INFL,0};
    for(auto i:mapa) minn=min(minn,{i.se,i.fi});
    ll pos=-1;
    forn(i, n) if(v[i]==minn.se) { pos=i; break; }
    forn(i, n) if(v[i]!=v[pos]) cout<<pos+1<<" "<<i+1<<"\n";
    vector < ll > eq,dis;
    forn(i, n) if(v[i]==v[pos]&&i!=pos) eq.push_back(i);
    forn(i, n) if(v[i]!=v[pos]&&i!=pos) dis.push_back(i);
    while(sz(eq))
    {
        cout<<eq.back()+1<<" "<<dis.back()+1<<"\n";
        dis.pop_back();
        eq.pop_back();
    }
}

void DDistrictsConnection(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}