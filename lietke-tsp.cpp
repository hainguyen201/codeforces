#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int N;
int X[MAX];
int appear[MAX];//appear[v]=1 indicates that v has appeared

void solution()
{
    cout<<"0: ";
    for(int i=1; i<=N; i++)
        cout<<X[i]<<" ";
    cout<<endl;
}
bool check(int v, int k)
{
    return appear[v]==0;
}
void TRY(int k)
{
    for(int v=1; v<=N; v++)
    {
        if(check(v, k))
        {
            X[k]=v;
            appear[v]=1;//update
            if(k==N)
                solution();
            else
                TRY(k+1);
            appear[v]=0;//recover;
        }
    }
}
void solve()
{
    for(int v=1; v<=N; v++)
        appear[v]=0;
    TRY(1);
}
int main()
{
    N=3;
    solve();

}
