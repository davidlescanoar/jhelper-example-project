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

pair < ll, ll > calc(ll cnts, ll cntw, ll s, ll w, ll p)
{
    pair < ll, ll > ma={0,0};
    fore(i, 0, cnts)
    {
        if(i*s<=p)
        {
            ll rem=p-i*s;
            ll cw=min(cntw,rem/w);
            if(((i+cw)>(ma.fi+ma.se)))
                ma={i,cw};
        }
    }
    return ma;
}

void solve(istream& cin, ostream& cout)
{
    ll p, f, cnts, cntw, s, w, rr=0;
    cin>>p>>f>>cnts>>cntw>>s>>w;
    pair < ll, ll > sa_1=calc(cnts, cntw, s, w, p), sa_2=calc(cntw, cnts, w, s, p);
    ll ra_1=sa_1.fi+sa_1.se, ra_2=sa_2.fi+sa_2.se;
    if(ra_1>=ra_2)
        cnts-=sa_1.fi, cntw-=sa_1.se, rr+=sa_1.fi+sa_1.se;
    else
        cnts-=sa_2.se, cntw-=sa_2.fi, rr+=sa_2.fi+sa_2.se;
    sa_1=calc(cnts, cntw, s, w, f), sa_2=calc(cntw, cnts, w, s, f);
    ra_1=sa_1.fi+sa_1.se, ra_2=sa_2.fi+sa_2.se;
    if(ra_1>=ra_2)
        rr+=sa_1.fi+sa_1.se;
    else
        rr+=sa_2.fi+sa_2.se;
    cout<<rr<<"\n";
}

void BRPGProtagonist(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}