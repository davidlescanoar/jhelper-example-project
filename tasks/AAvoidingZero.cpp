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
    ll n, sn=0,sp=0,z=0;
    cin>>n;
    vector < ll > v(n);
    forn(i, n) cin>>v[i];
    sort(all(v));
    forn(i, n)
    {
        if(v[i]<0) sn+=v[i];
        else if(v[i]>0) sp+=v[i];
        else z++;
    }
    if(!(sn+sp)){cout<<"NO\n";return;}
    cout<<"YES\n";
    if(abs(sn)<sp) sort(rall(v));
    forn(i, n)
    {
        if(!v[i]) continue;
        cout<<v[i]<<" ";
    }
    forn(i,z) cout<<"0 ";
    cout<<"\n";
}

void AAvoidingZero(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}