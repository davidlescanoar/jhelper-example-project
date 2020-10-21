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

void solve(istream& cin, ostream& cout)
{
    ll n, k, ck,rachas=1,L=0;
    bool flag=false,ban=false;
    string s;
    cin>>n>>k>>s;
    ck=k;
    multiset < ll > rangos;
    while(sz(s)&&s[sz(s)-1]=='L') s.pop_back();
    for(int j = 0; j < s.size(); j++)
    {
        if(s[j]=='W') flag=1;
        if(flag)
        {
            if(s[j]=='L'&&!ban) L=j,ban=1,rachas++;
            else if(s[j]=='W'&&ban) rangos.insert(j-1-L+1),ban=0;
        }
    }
    if(ban) rangos.insert(sz(s)-1-L+1);
    for(ll i:rangos)
    {
        if(i>k) break;
        k-=i;
        rachas--;
    }
    cout<<max(0LL,min(n,count(all(s),'W')+ck)*2-rachas)<<"\n";
}

void BChessCheater(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}