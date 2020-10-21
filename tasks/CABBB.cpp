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
    ll r=0,A=0,szz;
    string s;
    cin>>s;
    szz=sz(s);
    for(char &i:s)
    {
        if(i=='A')
        {
            A++;
            i='X';
            continue;
        }
        if(A) A--,i='X',szz-=2;
    }
    ll cant=count(all(s),'B');
    r=szz-(cant-(cant%2));
    cout<<(ll)r<<"\n";
}

void CABBB(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}