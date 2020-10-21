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

ll n, m;
vector < vector < ll > > v;
vector < vector < ll > > dp;
vector < vector < vector < ll > > > camino;

bool esValido(ll a, ll b){ return (a>=0&&a<n&&b>=0&&b<m); }

ll expected(ll a, ll b){ return (ll)(((b*(b+1))/2)-((((a-1)*a)/2)));}
ll faltan(ll k){ return (ll)(((n-1)+(m-1))-k); }

ll calcular(ll i, ll j, ll k)
{
    ll s=0;
    for(ll x:camino[i][j]) s+=abs(x-k++)-1;
    return s;
}

ll DP(ll i, ll j, ll k)
{
    if(i==n-1&&j==m-1) return 0;
    if(i==n||j==m) return INFL;
    if(dp[i][j]<INFL) return dp[i][j];
    if(DP(i+1,j,k+1)+(esValido(i+1,j)?abs(v[i+1][j]-v[i][j])-1:0)<dp[i][j])
    {

    }
    return dp[i][j];
}

void solve(istream& cin, ostream& cout)
{
    cin>>n>>m;
    v=dp=vector < vector < ll > >(n, vector < ll >(m,INFL));
    camino=vector < vector < vector < ll > > >();
    forn(i, n) forn(j, m) cin>>v[i][j];
    cout<<DP(0,0,0)<<"\n";
    forn(i, n)
    {
        forn(j, m)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"-----------------------------------------------------\n";
}

void FDecreasingHeights(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}