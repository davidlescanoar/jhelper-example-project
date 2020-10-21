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

ll nodos;
vector < ll > color;
vector < vector < ll > > adj;
vector < ll > res;

void dfs(ll nodo, ll k, ll padre)
{
    res[nodo]=k;
    for(ll i:adj[nodo])
        if(i!=padre)
            dfs(i,k+color[i],nodo);
}

void solve(istream& cin, ostream& cout)
{
    cin>>nodos;
    color.resize(nodos+1);
    adj.resize(nodos+1);
    fore(i, 1, nodos)
    {
        cin>>color[i];
        if(!color[i]) color[i]=-1;
    }
    forn(i, nodos-1)
    {
        ll desde, hasta;
        cin>>desde>>hasta;
        adj[desde].push_back(hasta);
        adj[hasta].push_back(desde);
    }
    fore(i, 1, nodos)
    {
        cout<<i<<"->";
        for(ll j:adj[i]) cout<<j<<" ";
        cout<<"\n";
    }
    fore(i, 1, nodos)
    {
        res=vector < ll >(nodos+1);
        dfs(i,color[i],-1);
        //cout<<*max_element(all(res))<<" ";
    }
    cout<<"\n";
}

void FMaximumWhiteSubtree(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}