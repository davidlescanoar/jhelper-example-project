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
    ll n, a=0, ab=0, abc=0, p=1;
    string s;
    cin>>n>>s;
    for(char i:s)
    {
        if(i=='a') a=(a+p)%MOD;
        else if(i=='b') ab=(ab+a)%MOD;
        else if(i=='c') abc=(abc+ab)%MOD;
        else
        {
            abc=((abc*3)%MOD+ab)%MOD;
            ab=(((ab*3)%MOD)+a)%MOD;
            a=(((a*3)%MOD)+p)%MOD;
            p=(p*3)%MOD;
        }
    }
    cout<<abc<<"\n";
}

void FNumberOfSubsequences(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}