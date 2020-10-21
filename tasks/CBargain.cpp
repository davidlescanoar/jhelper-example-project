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

const ll MOD=(ll)1e9+7;

void solve(istream& cin, ostream& cout)
{
    ll r=0;
    string s;
    cin>>s;
    vector < ll > pot10={1};
    while(sz(pot10)<100010) pot10.push_back((pot10.back()*10)%MOD);
    vector < ll > dp1(sz(s)+2,0);
    vector < ll > dp2(sz(s)+2,0);
    forn(i, sz(s)) dp1[i+1]=(((dp1[i]*10)%MOD)+(s[i]-'0'))%MOD;
    for(ll i=sz(s)-1,c=0;i>=0;i--,c++) dp2[i]=(((pot10[c]*(s[i]-'0'))%MOD)+dp2[i+1])%MOD;
    //for(ll i:dp2) cout<<i<<" ";
    //cout<<"\n";
    forn(i,sz(s))
    {
        fore(j, i, sz(s) - 1)
        {
            ll ss=(dp1[i]);//+dp2[j-1])%MOD;
            fore(x,j+1,sz(s)-1) ss=(((ss*10)%MOD)+(s[x]-'0'))%MOD;
            r=(r+ss)%MOD;
        }
    }
    cout<<r<<"\n";
}

void CBargain(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}