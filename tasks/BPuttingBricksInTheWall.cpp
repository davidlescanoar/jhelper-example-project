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
    cin>>n;
    vector < string > v(n);
    forn(i, n) cin>>v[i];
    vector < char > p1={'0','1'};
    vector < char > p2={'0','1'};
    forn(i,4)
    {
        char d1=p1[i];
        forn(j,4)
        {
            char d2=p2[j];
            if(d1==d2) continue;
            ll diff1=(v[0][1]!=d1)+(v[1][0]!=d1);
            ll diff2=(v[n-1][n-2]!=d2)+(v[n-2][n-1]!=d2);
            if(diff1+diff2<=2)
            {
                vector < pair < ll, ll > > r;
                if(v[0][1]!=d1) r.push_back({1,2});
                if(v[1][0]!=d1) r.push_back({2,1});
                if(v[n-1][n-2]!=d2) r.push_back({n,n-1});
                if(v[n-2][n-1]!=d2) r.push_back({n-1,n});
                cout<<sz(r)<<"\n";
                for(auto i:r) cout<<i.fi<<" "<<i.se<<"\n";
                return;
            }
        }
    }
    cout<<"0\n";
}

void BPuttingBricksInTheWall(istream& in, ostream& out)
{
    ll casos=1;
    in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}