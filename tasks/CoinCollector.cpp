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

ll nodos, aristas,s;
vector < ll > coins, id,orden,dp;
vector < vector < ll > > adj1, adj2, adj3;
bitset < (ll)1e5+10 > used,hijo;
set < pair < ll, ll > > proc;

void dfs1(ll nodo)
{
    used[nodo]=true;
    for(ll i:adj1[nodo]) if(!used[i]) dfs1(i);
    orden.push_back(nodo);
}

void dfs2(ll nodo, ll ID)
{
    used[nodo]=true;
    s+=coins[nodo];
    id[nodo]=ID;
    for(ll i:adj2[nodo]) if(!used[i]) dfs2(i,ID);
}

void dfs3(ll nodo)
{
    used[nodo]=true;
    for(ll i:adj2[nodo])
    {
        if(id[i]!=id[nodo]&&proc.find({id[i],id[nodo]})==proc.end())
        {
            proc.insert({id[i],id[nodo]});
            adj3[id[i]].push_back(id[nodo]);
        }
        if(!used[i]) dfs3(i);
    }
}

ll DP(ll nodo)
{
    if(dp[nodo]!=-1) return dp[nodo];
    ll s=0;
    for(ll i:adj3[nodo])
        s=max(s,DP(i));
    return dp[nodo]=s+coins[nodo];
}

void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>aristas;
    orden.clear();
    coins=id=vector < ll >(nodos+1,0);
    dp=vector < ll >(nodos+1,-1);
    adj1=adj2=adj3=vector < vector < ll > >(nodos+1);
    proc.clear();
    used.reset();
    hijo.reset();
    fore(i, 1, nodos) cin>>coins[i];
    forn(i, aristas)
    {
        ll desde, hasta;
        cin>>desde>>hasta;
        adj1[desde].push_back(hasta);
        adj2[hasta].push_back(desde);
    }
    fore(i, 1, nodos) if(!used[i]) dfs1(i);
    used.reset();
    for(ll i=nodos-1;i>=0;i--)
    {
        if(!used[orden[i]])
        {
            s=0;
            dfs2(orden[i],orden[i]);
            coins[orden[i]]=s;
        }
    }
    used.reset();
    ll maxx=0;
    for(ll i=nodos-1;i>=0;i--) if(!used[id[orden[i]]]) dfs3(id[orden[i]]);
    fore(i, 1, nodos) for(ll j:adj3[i]) hijo[j]=1;
    fore(i, 1, nodos) if(!hijo[id[i]]) maxx=max(maxx,DP(id[i]));
    cout<<maxx<<"\n";
}

void CoinCollector(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}