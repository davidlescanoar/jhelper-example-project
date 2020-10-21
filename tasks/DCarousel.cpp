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
    ll n, igual=-1;
    cin>>n;
    vector < ll > v(n);
    forn(i, n) cin>>v[i];
    forn(i, n) if(v[i]==v[(i+1)%n]) igual=i;
    if(count(all(v),v[0])==n)
    {
        cout<<"1\n";
        forn(i, n) cout<<"1 ";
        cout<<"\n";
        return;
    }
    if(!(n%2))
    {
        cout<<"2\n";
        forn(i, n) cout<<(i%2)+1<<" ";
        cout<<"\n";
        return;
    }
    if(igual!=-1)
    {
        cout<<"2\n";
        forn(i, n) cout<<((i+(i>igual))%2)+1<<" ";
        cout<<"\n";
        return;
    }
    cout<<"3\n";
    forn(i, n-1) cout<<(i%2)+1<<" ";
    cout<<"3\n";
}

void DCarousel(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}