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
    ll n,r=0,cc=0,k=0,d;
    string s;
    cin>>n>>s;
    char c=s[0]; s+='X';
    forn(i,n+1)
    {
        if(s[i]==c) cc++;
        else d=k,k=max(0LL,k-(cc-1)),cc-=(d-k),k+=(cc==1),r++,cc=1;
        c=s[i];
    }
    cout<<r-k/2<<"\n";
}

void DStringDeletion(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}