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

ll f(ll sq, ll n){ if(!sq)return INFL; return ((sq-1)+((n-1)/sq)); }

void solve(istream& cin, ostream& cout)
{
    ll n;
    cin>>n;
    ll sq=sqrt(n),sq2=sqrt(n)+1,sq3=sqrt(n)-1;
    cout<<(ll)min(f(sq,n), min(f(sq2,n), f(sq3,n)))<<"\n";
}

void CIncreaseAndCopy(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}