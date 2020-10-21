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
    ll n, k, rr=0;
    cin>>n>>k;
    vector < ll > x(n),y(n),l(n),r(n);
    forn(i, n) cin>>x[i];
    forn(i, n) cin>>y[i];
    sort(all(x));
    deque < ll > dq1,dq2;
    forn(i,n)
    {
        dq1.push_back(x[i]);
        while(dq1.front()<(dq1.back()-k)) dq1.pop_front();
        l[i]=sz(dq1);
        dq2.push_front(x[n-i-1]);
        while(dq2.back()>(dq2.front()+k)) dq2.pop_back();
        r[n-i-1]=sz(dq2);
    }
    fore(i, 1, n-1) l[i]=max(l[i],l[i-1]),r[n-i-1]=max(r[n-i-1],r[n-i]);
    forn(i, n) rr=max(rr,l[i]+((i+1<n)?r[i+1]:0));
    cout<<rr<<"\n";
}

void ETwoPlatforms(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}