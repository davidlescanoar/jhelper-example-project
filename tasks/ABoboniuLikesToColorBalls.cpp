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
    ll r, g, b, w;
    cin>>r>>g>>b>>w;
    ll c=min(1LL, min(r, min(g, b)));
    ll imp=r%2+g%2+b%2+w%2;
    if(imp>1)
    {
        r-=c, g-=c, b-=c, w+=c;
        imp=r%2+g%2+b%2+w%2;
        if(imp>1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else
        cout << "Yes\n";
}

void ABoboniuLikesToColorBalls(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}