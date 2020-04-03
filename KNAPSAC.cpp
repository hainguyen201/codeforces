#include <iostream>
#include <utility>
#include <map>
#include <limits.h>
using namespace std;

#define MAX 40
typedef pair<int, int> pii;
int N, B, amin = INT_MAX;
pii X[MAX];
pii x[MAX];
bool carried[MAX] = {false};
int fc = 0, fc_best = INT_MIN, fa, amax=0, cmax=0;
void input()
{
    cin >> N >> B;
    int a, c; //trong luong va gia tri
    for (int i = 1; i <= N; i++)
    {
        cin >> a >> c;
        X[i] = make_pair(a, c);
        if (a < amin)
            amin = a;
        amax+=a;
        cmax+=c;
    }
}
bool check(int i, int k)
{
    if ((fa + X[i].first <= B) && carried[i] == false)
        return true;
    return false;
}
bool check2(int i, int k)
{
    if (fa + X[i].first > B && carried[i] == false)
        return true;
    return false;
}
void TRY(int k)
{
    for (int i = k; i <= N; i++)
    {
        if (check(i, k))
        {
            fa += X[i].first;
            fc += X[i].second;
            carried[i]=true;
            if(X[i].first+amin<=B) TRY(k+1);
            carried[i]=false;
            fa -= X[i].first;
            fc -= X[i].second;

        }
        else
        {
            if(check2(i, k))
            {
                if(fc>fc_best)
                    fc_best=fc;
            }
        }
    }
}
void solve()
{
    input();
    if(amax<=B)
        cout<<cmax;
    else
    {
        TRY(1);
        cout<<fc_best;
    }

}
int main()
{
    solve();
}




