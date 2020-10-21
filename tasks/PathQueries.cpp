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

ll nodos, q;
ll costo[MAXN],cant[MAXN],peso[MAXN],pos[MAXN];
vector < ll > adj[MAXN];
vector < ll > recorrido;
ll ft[MAXN];
ll dfs(ll nodo, ll padre, ll dd)
{
    recorrido.push_back(nodo);
    peso[nodo]=dd;
    for(ll i:adj[nodo]) if(i!=padre) cant[nodo]+=dfs(i,nodo,dd+costo[i]);
    return cant[nodo]+1;
}
ll upd(ll p,ll val){ for(ll i=p;i<MAXN;i+=(i&-i)) ft[i]+=val; }
ll get(ll p){ ll s=0; for(ll i=p;i;i-=(i&-i)) s+=ft[i]; return s; }

void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>q;
    fore(i, 1, nodos) cin>>costo[i];
    forn(i,nodos-1)
    {
        ll desde, hasta;
        cin>>desde>>hasta;
        adj[desde].push_back(hasta);
        adj[hasta].push_back(desde);
    }
    recorrido={0};
    dfs(1,-1,costo[1]);
    fore(i, 1, nodos) pos[recorrido[i]]=i;
    fore(i,1,nodos) upd(pos[i],peso[i]),upd(pos[i]+1,-peso[i]);
    while(q--)
    {
        ll t,s,x;
        cin>>t;
        if(t==1)
        {
            cin>>s>>x;
            ll sum=get(pos[s]);
            upd(pos[s],x-costo[s]);
            upd(pos[s]+cant[s]+1,-x+costo[s]);
            costo[s]=x;
        }
        else
        {
            cin>>s;
            ll sum=get(pos[s]);
            cout<<sum<<"\n";
        }
    }
}

void PathQueries(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}