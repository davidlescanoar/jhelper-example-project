#include <bits/stdc++.h>
typedef long long ll;
const int INFI=(1<<29);
#define sz(x) int(x.size())
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(tourBina,n) for(int tourBina=0;tourBina<n;tourBina++)
#define fore(tourBina,l,r) for(int tourBina=l;tourBina<=r;tourBina++)
using namespace std;
const int LVL=19;
const int MAXN=(1<<LVL);
int d[MAXN];
int nodos,q,a,b;
bool fcmp(int a, int b){ return d[a]<d[b]; }
int vec[LVL][MAXN];
int mn(int i, int j)
{
    int p=31-__builtin_clz(j-i);
    return min(vec[p][i],vec[p][j-(1<<p)],fcmp);
}
void mn_init(int n)
{
    int mp=31-__builtin_clz(n);
    forn(p,mp) forn(x,n-(1<<p)) vec[p+1][x]=min(vec[p][x],vec[p][x+(1<<p)],fcmp);
}
vector < int > t[MAXN];
int pos[MAXN];
int id,pp;
void dfs(int x)
{
    d[x]=id++;
    vec[0][pos[x]=pp++]=x;
    for(int y:t[x])
    {
        if(d[y]==-1)
        {
            dfs(y);
            vec[0][pp++]=x;
        }
    }
}
void lcaInit(int n, int raiz)
{
    id=pp=0;
    memset(d,-1,sizeof(d));
    dfs(raiz);
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
    cin>>nodos>>q;
    fore(i, 2, nodos) cin>>a,t[a].push_back(i);
    lcaInit(nodos,1);
    while(q--)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
}
void CompanyQueriesII(istream& in, ostream& out){ solve(in, out); }