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

const ll MAXN=(ll)2e5+10;
ll nodos,r;
vector < ll > adj[MAXN];
bitset < MAXN > used;

void dfs(ll nodo, ll padre)
{
    for(ll i:adj[nodo]) if(i!=padre) dfs(i,nodo);
    if(padre!=-1&&!used[padre]&&!used[nodo])
    {
        r++;
        used[padre]=used[nodo]=1;
    }
}

void solve(istream& cin, ostream& cout)
{
    cin>>nodos;
    forn(i,nodos-1)
    {
        ll desde,hasta;
        cin>>desde>>hasta;
        adj[desde].push_back(hasta);
        adj[hasta].push_back(desde);
    }
    dfs(1,-1);
    cout<<r<<"\n";
}

void TreeMatching(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}