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
    ll n;
    string s;
    cin>>n>>s;
    vector < ll > par, imp;
    if(n%2)
    {
        ll p=0;
        fore(i,p,n-1)
        {
            ll d=s[i]-'0';
            if(d%2)
            {
                cout<<"1\n";
                return;
            }
            i++;
        }
        cout<<"2\n";
        return;
    }
    ll p=1;
    fore(i,p,n-1)
    {
        ll d=s[i]-'0';
        if(!(d%2))
        {
            cout<<"2\n";
            return;
        }
        i++;
    }
    cout<<"1\n";
}

void ADigitGame(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}