/**
https://pastebin.com/NB77BUXT
https://pastebin.com/gTEiDAhz
**/

#include <bits/stdc++.h>

using namespace std;

vector < int > LIS(const vector < int > &v)
{
    int n=(int)v.size(), sl=0;
    vector < int > pad(n,-1),p(n,0),t(n, v[0]), lis;
    for(int i=1;i<n;i++)
    {
        if(v[i]>t[sl]) t[++sl]=v[i], p[sl]=i, pad[i]=p[sl-1];
        else if(v[i]<t[0]) t[0]=v[i], p[0]=i;
        else
        {
            int ind=lower_bound(t.begin(), t.begin()+sl, v[i])-t.begin();
            t[ind]=v[i], p[ind]=i, pad[i]=p[ind-1];
        }
    }
    int ind=p[sl];
    do lis.push_back(v[ind]), ind=pad[ind]; while(ind!=-1);
    reverse(lis.begin(), lis.end());
    return lis;
}

void solve(istream& cin, ostream& cout)
{
    int in;
    vector < int > v;
    while(cin>>in) v.push_back(in);
    vector < int > lis=LIS(v);
    cout<<(int)lis.size()<<"\n-\n";
    for(int i:lis) cout<<i<<"\n";
}

void WhatGoesUp(istream& in, ostream& out)
{
    int casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}