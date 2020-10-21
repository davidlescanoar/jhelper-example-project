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
    ll n,r=0;
    cin>>n;
    fore(i, 1, 9)
    {
        ll d=i,rr=0;
        if(i==n%10)
        {
            while(d<=n)
            {
                rr++;
                r+=rr;
                d=(d*10)+i;
            }
            break;
        }
        else
        {
            while(d<=10000)
            {
                rr++;
                r+=rr;
                d=(d*10)+i;
            }
        }
    }
    cout<<r<<"\n";
}

void ABoringApartments(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}