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

const int MAXN=(ll)2e5+10;
int nodos, q,t;
vector < int > adj[MAXN];
int dist[MAXN],p[MAXN],in[MAXN],out[MAXN];

void dfs(int nodo, int padre, int d)
{
    in[nodo]=t++;
    dist[nodo]=d;
    p[nodo]=padre;
    for(int i:adj[nodo]) if(i!=padre) dfs(i,nodo,d+1);
    out[nodo]=t++;
}

void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>q;
    forn(i, nodos-1)
    {
        ll desde, hasta;
        cin>>desde>>hasta;
        adj[desde].push_back(hasta);
        adj[hasta].push_back(desde);
    }
    dfs(1,-1,0);
    while(q--)
    {
        int k;
        cin>>k;
        vector < int > query(k);
        pair < int, int > maxx={-INFL,0};
        forn(i,k)
        {
            cin>>query[i];
            maxx=max(maxx,{dist[query[i]],query[i]});
        }
        bool ok=true;
        for(int &i:query)
        {
            if(i!=1) i=p[i];
            ok&=(in[maxx.se]>=in[i]&&out[maxx.se]<=out[i]);
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

void ETreeQueries(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}