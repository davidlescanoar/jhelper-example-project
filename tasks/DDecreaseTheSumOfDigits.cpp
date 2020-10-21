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
    ll n, no, s, sum=0;
    cin>>n>>s;
    no=n;
    string ss=to_string(n);
    for(char i:ss) sum+=(i-'0');
    if(sum<=s){ cout<<0<<"\n"; return; }
    vector < ll > pot10={1};
    while(sz(pot10)<=18) pot10.push_back(pot10.back()*10);
    for(ll i=sz(ss)-1;i>=0;i--)
    {
        ll d=(ss[i]-'0');
        if(!d) continue;
        n+=(10-d)*pot10[sz(ss)-i-1];
        ss=to_string(n);
        sum=0;
        for(char j:ss) sum+=(j-'0');
        if(sum<=s){ cout<<(ll)n-no<<"\n"; return; }
    }
}

void DDecreaseTheSumOfDigits(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}