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
struct arista{ll nodo,cantidad,ind;};
ll nodos, S;
vector < vector < arista > > adj;
vector < ll > cantidad, peso, costo;
ll dfs(ll nodo, ll padre)
{
    ll k=0;
    for(arista i:adj[nodo])
    {
        if(i.nodo!=padre)
        {
            ll d=dfs(i.nodo, nodo);
            cantidad[i.ind]+=d;
            k+=d;
        }
    }
    if(!k) return 1;
    return k;
}
ll getdiff(ll p,ll cnt){ return (p*cnt-(p/2)*cnt); }
void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>S;
    adj.clear();
    adj=vector < vector < arista > >(nodos+1);
    cantidad.clear();
    cantidad=vector < ll >(nodos-1,0);
    costo.clear();
    costo=vector < ll >(nodos-1,0);
    peso.clear();
    peso=vector < ll >(nodos-1,0);
    forn(i,nodos-1)
    {
        ll desde,hasta,cantidad,cc;
        cin>>desde>>hasta>>cantidad>>cc;
        adj[desde].push_back({hasta,cantidad,i});
        adj[hasta].push_back({desde,cantidad,i});
        peso[i]=cantidad;
        costo[i]=cc;
    }
    dfs(1,-1);
    ll sum=0,r=0;
    multiset < pair < ll, ll > > s;
    forn(i, nodos-1) s.insert({-getdiff(peso[i],cantidad[i]),i}),sum+=cantidad[i]*peso[i];
    while(sum>S)
    {
        auto it=s.begin();
        pair < ll, ll > k=(*it);
        s.erase(it);
        sum-=peso[k.second]*cantidad[k.second];
        peso[k.second]/=2;
        sum+=peso[k.second]*cantidad[k.second];
        s.insert({-getdiff(peso[k.second],cantidad[k.second]),k.second});
        r++;
    }
    cout<<r<<"\n";
}
void E1WeightsDivisionEasyVersion(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}