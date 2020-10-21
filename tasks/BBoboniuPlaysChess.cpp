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

ll n, m, x, y;
vector < pair < ll, ll > > r;
bitset < 110 > used[110];
bool ok=false;

void DFS(ll i, ll j)
{
    ll last=-1;
    if(!ok)
    {
        fore(k, 1, m) if(!used[i][k]) r.push_back({i, k}), used[i][k]=true, last=k;
        if(last==-1) return;
        ok=!ok;
        DFS(i, last);
    }
    else
    {
        fore(k, 1, n) if(!used[k][j]) r.push_back({k, j}), used[k][j]=true, last=k;
        if(last==-1) return;
        ok=!ok;
        DFS(last, j);
    }
}

void solve(istream& cin, ostream& cout)
{
    cin>>n>>m>>x>>y;
    r.push_back({x, y});
    used[x][y]=true;
    DFS(x, y);
    for(pair < ll, ll > i:r)
        cout << i.fi << " " << i.se << "\n";
}

void BBoboniuPlaysChess(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}