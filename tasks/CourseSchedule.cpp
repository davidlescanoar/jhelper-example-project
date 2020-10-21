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

ll nodos, aristas;
bitset < (ll)1e5+10 > used;

void solve(istream& cin, ostream& cout)
{
    cin>>nodos>>aristas;
    deque < ll > dq;
    used.reset();
    forn(i, aristas)
    {
        ll desde, hasta;
        cin>>desde>>hasta;
        if(!used[desde])
            dq.push_front(desde);
        if(!used[hasta])
            dq.push_back(hasta);
        used[desde]=used[hasta]=1;
    }
    fore(i, 1, nodos) if(!used[i]) dq.push_back(i);
    for(ll i:dq) cout << i << " ";
    cout << "\n";
}

void CourseSchedule(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}