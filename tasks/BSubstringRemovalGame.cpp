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
    string s;
    cin>>s;
    ll c=0;
    vector < ll > v;
    forn(i, sz(s))
    {
        if(s[i]=='1')
            c++;
        else
        {
            v.push_back(c);
            c=0;
        }
    }
    if(c)
        v.push_back(c);
    sort(rall(v));
    ll r=0;
    forn(i, sz(v))
        r+=v[i++];
    cout << r << "\n";
}

void BSubstringRemovalGame(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}