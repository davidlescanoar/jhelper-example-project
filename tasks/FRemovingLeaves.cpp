#include <bits/stdc++.h>

const int INFI=(1<<29);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) int(x.size())
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define forn(tourBina,n) for(int tourBina=0;tourBina<n;tourBina++)
#define fore(tourBina,l,r) for(int tourBina=l;tourBina<=r;tourBina++)
#define DBG(x) cerr<<#x<<" = "<<x<< endl

using namespace std;

int nodos, k;
vector < set < int > > adj;
vector < int > hp;

int get(int nodo){ return hp[nodo]; }

void sacarHojas(int nodo, int lv, set < pair < int, int > > &hojas)
{
    int cc=0;
    vector < int > sacados;
    for(int i:adj[nodo])
    {
        if(sz(adj[i])==1)
            hojas.erase({hp[i],i}),hp[i]=0,hp[nodo]--,adj[i].clear(),cc++,sacados.push_back(i);
        if(cc==k) break;
    }
    for(int i:sacados) adj[nodo].erase(i);
    if(sz(adj[nodo])==1)
    {
        int padre=*adj[nodo].begin();
        hojas.erase({hp[padre],padre});
        hp[padre]++;
        hojas.insert({-get(padre),padre});
    }
    else
        hojas.insert({-get(nodo),nodo});
}

void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>k;
    adj=vector < set < int > >(nodos+1);
    set < pair < int, int > > hojas;
    hp=vector < int >(nodos+1,0);
    forn(i,nodos-1)
    {
        int desde, hasta;
        cin>>desde>>hasta;
        adj[desde].insert(hasta);
        adj[hasta].insert(desde);
    }
    fore(i,1,nodos) if(sz(adj[i])==1) hp[*adj[i].begin()]++;
    int r=0;
    fore(i,1,nodos) hojas.insert({-get(i),i});
    while(sz(hojas))
    {
        auto it=hojas.begin();
        int h=-(*it).first;
        int nodo=(*it).second;
        hojas.erase(it);
        if(get(nodo)!=h) continue;
        if(h<k) break;
        sacarHojas(nodo,-h,hojas);
        r++;
    }
    cout<<r<<"\n";
}

void FRemovingLeaves(istream& in, ostream& out)
{
    int casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}