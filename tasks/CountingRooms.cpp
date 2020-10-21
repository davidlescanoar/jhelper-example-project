#include <bits/stdc++.h>

using namespace std;

///Filas y columnas
int n, m, r=0;
vector < string > v;

///Direcciones
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

///Funcion para validar celda
bool esValido(const int &a, const int &b){ return ((a>=0)&&(a<n)&&(b>=0)&&(b<m)); }

void floodfill(int i, int j)
{
    v[i][j]='#';
    for(int k=0; k<4; k++)
    {
        int ii=i+dx[k];
        int jj=j+dy[k];
        if(esValido(ii, jj)&&(v[ii][jj]=='.'))
            floodfill(ii,jj);
    }
}

void solve(istream& cin, ostream& cout)
{
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='.')
            {
                floodfill(i, j);
                r++;
            }
        }
    }
    cout<<r<<"\n";
}

void CountingRooms(istream& in, ostream& out)
{
    int casos=1;
    //in>>casos;
    while(casos--)
    {
        solve(in, out);
    }
}