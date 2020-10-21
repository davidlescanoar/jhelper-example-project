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

ll divi(ll n, ll lim)
{
    fore(i, 1, n)
    {
        if(!(n%i)&&((n/i)+1<=lim))
        {
            return i;
        }
    }
    return n;
}

void solve(istream& cin, ostream& cout)
{
    ll n,x,y;
    cin>>n>>x>>y;
    ll diff=y-x;
    ll div=divi(diff, n);
    //DBG(divi);
    deque < ll > dq;
    for(ll i=x; i<=y; i+=div)
        dq.push_back(i);
    ll ind=x-div;
    while((dq.size()<n)&&(ind>=1))
    {
        dq.push_back(ind);
        ind-=div;
    }
    ind=y+div;
    while((dq.size()<n))
    {
        dq.push_back(ind);
        ind+=div;
    }
    for(ll i:dq) cout<<i<<" ";
    cout<<"\n";
}

void CYetAnotherArrayRestoration(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}