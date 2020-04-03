#include <bits/stdc++.h>
using namespace std;
#define MAX 30
int N, M, cmin=INT_MAX;
int c[MAX];
int A[MAX][MAX];

int X[MAX];

int load[MAX];
int f_best;
void input()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        cin>>c[i];
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>A[i][j];
        }
    }
}

bool check(int v, int k)
{
    for(int i=1; i<=k-1; i++)
    {
        if(A[k][i]==1)
        {
            if(X[i]>=v)
                return false;
        }
        if(A[i][k]==1)

        {
            if(X[i]<=v)
                return false;
        }
    }
    return true;
}
void solution()
{
    int max_load =0;
    for(int j=1; j<=M; j++)
    {
        if(max_load<load[j])
            max_load=load[j];
    }
    if(max_load<f_best)
        f_best=max_load;
}
void TRY(int k)
{
    for(int v=1; v<=M; v++)
    {
        if(check(v, k))
        {
            X[k]=v;//gan khoa hoc k vao hoc ki v
            load[v]=load[v]+c[k];
            if(k==N)
                solution();
            else
            {
                TRY(k+1);
            }
            load[v]=load[v]-c[k];
        }
    }
}
void solve()
{
    f_best=10000000;
    for(int j=1; j<=M; j++)
        load[j]=0;
    TRY(1);
    cout<<f_best;
}
int main()
{
    input();
    solve();
}
