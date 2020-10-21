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
    ll n,f=1;
    cin>>n;
    vector < ll > v(n);
    forn(i, n) cin>>v[i];
    vector < pair < ll, ll > > r;
    deque < pair < ll, ll > > q;
    vector < bool > usado(n+1,false);
    for(ll i=n-1;i>=0;i--)
    {
        if(!v[i]) continue;
        if(v[i]==1)
        {
            r.push_back({f++,i+1});
            q.push_front(r.back());
        }
        else if(v[i]==2)
        {
            if(q.empty()){cout<<"-1\n";return;}
            pair < ll, ll > p=q.back();
            q.pop_back();
            r.push_back({p.fi,i+1});
        }
        else
        {
            while(!q.empty()&&usado[q.front().fi]) q.pop_front();
            if(q.empty()){cout<<"-1\n";return;}
            pair < ll, ll > p=q.front();
            q.pop_front();
            r.push_back({p.fi,i+1});
            usado[p.fi+1]=true;
            if(p.fi+1>n){cout<<"-1\n";return;}
            r.push_back({p.fi+1,p.se});
            f=p.fi+2;
        }
    }
    cout<<sz(r)<<"\n";
    for(pair < ll, ll > i:r) cout<<i.fi<<" "<<i.se<<"\n";
    if(sz(r)) cout<<"\n";
}

void DBouncingBoomerangs(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}