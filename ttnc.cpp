#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, x[MAX], fopt, fcur, xopt[MAX];
int visited[MAX]= {0}, c[MAX][MAX], cmin=1000;

void input()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>c[i][j];
            if(c[i][j]<cmin && i!=j)
                cmin=c[i][j];
        }
}
void TRY(int k)
{
    //1, x2, x3,..xk-1
    for(int i=2; i<=n; i++)
    {
        if(visited[i]==0)
        {
            x[k]=i;
            fcur+=c[x[k-1]][i];
            visited[i]=1;
            if(k==n)
            {
                if(fcur+c[i][1]<fopt)
                {
                    fopt=fcur+c[i][1];
                    for(int j=1; j<=n; j++)
                        xopt[j]=x[j];
                }
            }else if(fcur+(n-k+1)*cmin<fopt) TRY(k+1);
            fcur-=c[x[k-1]][i];
            visited[i]=0;
        }
    }
}
int main()
{
    input();
    x[1]=1;
    visited[1]=1;
    fopt=INT_MAX;
    fcur=0;
    TRY(2);
    cout<<"chi phi tot nhat: "<<fopt<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<xopt[i]<<"->";
    }
}
