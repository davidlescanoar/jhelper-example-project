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
    ll r, g, b;
    cin>>r>>g>>b;
    vector < ll > R(r), G(g), B(b);
    forn(i, r) cin>>R[i];
    forn(i, g) cin>>G[i];
    forn(i, b) cin>>B[i];
    sort(all(R));
    sort(all(G));
    sort(all(B));
    ll res=0;
    while((!sz(R)+!sz(G)+!sz(B))<2)
    {
        vector < pair < ll, char > > v;
        if(sz(R)) v.push_back({R.back(), 'r'});
        if(sz(G)) v.push_back({G.back(), 'g'});
        if(sz(B)) v.push_back({B.back(), 'b'});
        sort(rall(v));
        forn(i, 2)
        {
            if(v[i].se=='r') R.pop_back();
            else if(v[i].se=='g') G.pop_back();
            else B.pop_back();
        }
        res+=v[0].fi*v[1].fi;
    }
    cout << res << "\n";
}

void DColoredRectangles(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}