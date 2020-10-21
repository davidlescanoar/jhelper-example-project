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

bool vale(const string &s, const ll &k)
{
    ll u=0,z=0;
    forn(i, sz(s))
    {
        u+=(s[i]=='1');
        z+=(s[i]=='0');
        if(i>k-1)
        {
            u-=(s[i-k]=='1');
            z-=(s[i-k]=='0');
        }
        if((i>=k-1)&&!((u==(k/2))&&(z==(k/2))))
            return false;
    }
    return true;
}

string toStri(string s, const vector < bool > &p, char c1, char c2)
{
    ll c=0;
    vector < char > vc={c1,c2};
    forn(i, sz(s))
    {
        if(p[i])
        {
            s[i]=vc[c%2];
            c++;
        }
    }
    return s;
}

void solve(istream& cin, ostream& cout)
{
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector < bool > p(n);
    forn(i, n) p[i]=(s[i]=='?');
    string r="NO";
    if( vale(toStri(s,p,'0','0'),k)||
        vale(toStri(s,p,'1','1'),k)||
        vale(toStri(s,p,'0','1'),k)||
        vale(toStri(s,p,'1','0'),k) )
        r="YES";
    cout<<r<<'\n';
}

void CBalancedBitstring(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}