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
    ll n, k, c, x, y, r=0, ca,cb;
    cin>>n>>k;
    ca=cb=k;
    multiset < ll > alice,bob,ambos,ealice, ebob;
    forn(i, n)
    {
        cin>>c>>x>>y;
        if(x&&y) ambos.insert(c);
        else if(x) alice.insert(c);
        else bob.insert(c);
    }
    forn(i, ca)
    {
        if(sz(alice))
        {
            auto it=alice.begin();
            r+=*it;
            ealice.insert(*it);
            alice.erase(it);
            ca--;
        }
    }
    forn(i, cb)
    {
        if(sz(bob))
        {
            auto it=bob.begin();
            r+=*it;
            ebob.insert(*it);
            bob.erase(it);
            cb--;
        }
    }
    while(sz(ambos))
    {
        ll i=*ambos.begin();
        if(sz(ealice)&&sz(ebob)&&i<(*prev(ealice.end())+*prev(ebob.end())))
        {
            auto it=prev(ealice.end());
            alice.insert(*it);
            r-=*it;
            ealice.erase(it);
            it=prev(ebob.end());
            bob.insert(*it);
            r-=*it;
            ebob.erase(it);
            r+=i;
            ambos.erase(ambos.begin());
        } else break;
    }
    forn(i, ca)
    {
        if(sz(alice))
        {
            auto it=alice.begin();
            r+=*it;
            ealice.insert(*it);
            alice.erase(it);
            ca--;
        }
    }
    forn(i, cb)
    {
        if(sz(bob))
        {
            auto it=bob.begin();
            r+=*it;
            ebob.insert(*it);
            bob.erase(it);
            cb--;
        }
    }
    while(ca>0||cb>0)
    if(ca>0||cb>0){cout<<"-1\n";return;}
    cout<<r<<"\n";
}

void E1ReadingBooksEasyVersion(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}