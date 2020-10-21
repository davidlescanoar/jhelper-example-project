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
    ll n, minn=0, maxx=0;
    cin>>n;
    vector < ll > a(3), b(3);
    forn(i, 3) cin>>a[i];
    forn(i, 3) cin>>b[i];
    forn(i, 3) maxx+=min(a[i],b[(i+1)%3]);
    forn(i, 3) minn+=min(b[i]+b[(i+1)%3],a[(i+1)%3]);
    cout<<n-minn<<" "<<maxx<<"\n";
}

void ERockPaperScissors(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}