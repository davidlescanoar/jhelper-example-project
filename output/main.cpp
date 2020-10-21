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

int n,m,k,r;
int v[75][75],dp[37][70];

void solve(istream& cin, ostream& cout)
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    forn(i, n) forn(j, m) cin>>v[i][j];
    dp[0][0]=0;
    forn(pos,n)
    {
        forn(j,k) dp[0][j]=max(dp[0][j],dp[m/2][j]);
        for(int val:v[pos])
            for(int i=m/2;i>=0;i--)
                for(int j=k-1;j>=0;j--)
                    if(dp[i][j]!=-1)
                        dp[i+1][(j+val)%k]=max(dp[i+1][(j+val)%k],dp[i][j]+val);
    }
    cout<<dp[m/2][0]<<"\n";
}

void FZeroRemainderSum(istream& in, ostream& out)
{
    ll casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}

int main()
{
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    FIO;
    #ifdef tourBina
        ///freopen("input.in", "r", stdin);
    #endif
    FZeroRemainderSum(in, out);
    return 0;
}
