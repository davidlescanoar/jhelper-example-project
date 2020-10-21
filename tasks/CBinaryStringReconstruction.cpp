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
    string s;
    ll x;
    cin>>s>>x;
    vector < ll > r(sz(s), -1);
    ll n=sz(s);
    forn(i, n)
    {
        if(s[i]=='0')
        {
            if(i-x>=0)
            {
                if(r[i-x]==1){cout<<"-1"; return;}
                else r[i-x]=0;
            }
            if(i+x<n)
            {
                if(r[i+x]==1){cout<<"-1"; return;}
                else r[i+x]=0;
            }
        }
        else
        {
            if(i-x>=0)
            {
                if(r[i-x]==0){cout<<"-1"; return;}
                else r[i-x]=1;
            }
            if(i+x<n)
            {
                if(r[i+x]==0){cout<<"-1"; return;}
                else r[i+x]=1;
            }
        }
    }
    if(count(all(r),-1)){cout<<"-1"; return;}
    for(ll i:r)
        cout<<i;
    cout<<"\n";
}

void CBinaryStringReconstruction(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}