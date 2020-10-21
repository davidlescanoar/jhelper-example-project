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
    int n, m;
    cin>>n>>m;
    vector < int > a(n), b(m);
    forn(i, n) cin>>a[i];
    forn(i, m) cin>>b[i];
    bitset < 520 > s;
    s[0]=1;
    forn(i, n)
    {
        bitset < 520 > s2;
        forn(j, m)
        {
            ll v=a[i]&b[j];
            forn(k, 512)
                if(s[k])
                    s2[k|v]=1;
        }
        s=s2;
    }
    forn(i, 512)
    {
        if(s[i])
        {
            cout << i << "\n";
            return;
        }
    }
}

void CBoboniuAndBitOperations(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}