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
    ll n,ind=0,in;
    cin>>s>>n;
    string t(n,'#');
    vector < pair < ll, ll > > v;
    forn(i, n) cin>>in,v.push_back({in,i});
    sort(rall(s)); sort(all(v));
    DBG(s);
    forn(i, n)
    {
        ll k=v[i].fi,p=v[i].se;
        if(t[p]!='#') continue;
        forn(j,n) if(t[j]>s[ind]) k-=abs(j-p);
        if(k&&p+k>=0&&p+k<n&&t[p+k]=='#') t[p+k]=s[ind++];
        if(k&&p-k>=0&&p-k<n&&t[p-k]=='#') t[p-k]=s[ind++];
        t[p]=s[ind++];
        DBG(t);
    }
    DBG("---------------------------------");
    cout<<t<<"\n";
}

void DTaskOnTheBoard(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}