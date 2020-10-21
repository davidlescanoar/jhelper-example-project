#include <bits/stdc++.h>

#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(tourBina,n) for(int tourBina=0;tourBina<n;tourBina++)

using namespace std;

const int LVL=19;
const int MAXN=(1LL<<LVL);
int d[MAXN],dist[MAXN];
bool fcmp(int a, int b){ return d[a]<d[b]; }
int vec[LVL][MAXN];
int mn(int i, int j)
{
    int p=31-__builtin_clz(j-i);
    return min(vec[p][i],vec[p][j-(1<<p)],fcmp);
}
int mn_init(int n)
{
    int mp=31-__builtin_clz(n);
    forn(p,mp) forn(x,n-(1<<p)) vec[p+1][x]=min(vec[p][x],vec[p][x+(1<<p)],fcmp);
}
vector < int > adj[MAXN];
int pos[MAXN];
int id,pp;
void dfs(int x, int dd)
{
    dist[x]=dd;
    d[x]=id++;
    vec[0][pos[x]=pp++]=x;
    for(int &y:adj[x])
    {
        if(d[y]==-1)
        {
            dfs(y,dd+1);
            vec[0][pp++]=x;
        }
    }
}
void lcaInit(int n, int raiz)
{
    id=pp=0;
    memset(d,-1,sizeof(d));
    dfs(raiz,0);
    mn_init(2*n-1);
}
int lca(int i, int j)
{
    int a=pos[i],b=pos[j];
    if(a>b) swap(a,b);
    return mn(a,b+1);
}

void solve(istream& cin, ostream& cout)
{
    int nodos,q,desde,hasta,a,b;
    scanf("%d %d",&nodos,&q);
    forn(i,nodos-1)
    {
        scanf("%d %d",&desde,&hasta);
        adj[desde].push_back(hasta);
        adj[hasta].push_back(desde);
    }
    lcaInit(nodos,1);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",dist[a]+dist[b]-2*dist[lca(a,b)]);
    }
}

void DistanceQueries(istream& in, ostream& out)
{
    int casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}