#include <bits/stdc++.h>
using namespace std;
#define V_MAX 100
int M, N, c=1, cmin=INT_MAX;
int f_min=0, f_best=100000000;
int X[V_MAX][V_MAX], x[V_MAX];//X[i][j] la khoang cach tu canh i den j
bool visited[V_MAX]= {false};

void input()
{

    int v1, v2, c;
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            X[i][j]=0;
    for(int i=1; i<=M; i++)
    {
        cin>>v1>>v2>>c;
        X[v1][v2]=c;
        if(c<cmin)
            cmin=c;
    }
}
void TRY(int k)
{
    for(int v=2; v<=N; v++)
    {
        if(visited[v]==false && X[x[k-1]][v]>0)
        {
            x[k]=v;
            visited[v]=true;
            f_min+=X[x[k-1]][v];
            if(k==N)
            {
                if(X[v][1]>0 && (X[v][1]+f_min<f_best))
                {
                    f_best=f_min+X[v][1];

                }
            }
            else
            {
                if(f_min+(N-k)*cmin<f_best)
                    TRY(k+1);
            }
            f_min-=X[x[k-1]][v];
            visited[v]=false;
        }
    }
}
void solve()
{
    visited[1]=true;
    x[1]=1;
    TRY(2);
    cout<<f_best;
}
int main()
{
    input();
    solve();
}
