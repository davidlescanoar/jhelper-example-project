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

ll nodos, aristas,nc=0;
vector < vector < ll > > adj1,adj2;
bitset < (ll)1e5+10> used;
vector < ll > orden, comp;

void dfs1(ll nodo)
{
    used[nodo]=true;
    for(ll i:adj1[nodo]) if(!used[i]) dfs1(i);
    orden.push_back(nodo);
}
void dfs2(ll nodo, ll numComp)
{
    used[nodo]=true;
    comp[nodo]=numComp;
    for(ll i:adj2[nodo]) if(!used[i]) dfs2(i,numComp);
}

void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>aristas;
    adj1.resize(nodos+1);
    adj2.resize(nodos+1);
    comp.resize(nodos+1);
    forn(i, aristas)
    {
        ll desde, hasta;
        cin>>desde>>hasta;
        adj1[desde].push_back(hasta);
        adj2[hasta].push_back(desde);
    }
    fore(i, 1, nodos) if(!used[i]) dfs1(i);
    used.reset();
    for(ll i=nodos-1;i>=0;i--) if(!used[orden[i]]) dfs2(orden[i],++nc);
    cout<<nc<<"\n";
    fore(i, 1, nodos) cout<<comp[i]<<" ";
    cout<<"\n";
}

void PlanetsAndKingdoms(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}