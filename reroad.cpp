#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
long long a[MAX];
vector<int> result;
int main()
{
    int n, q, g = 1;
    cin >> n;
    cin >> a[1];
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] != a[i - 1])
                g++;
        }
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            long long p, c;
            cin >> p >> c;
            //voi p=1
            if (p == 1)
            {
                if (a[1] == a[2] && c != a[2])
                {
                    g++;
                    result.push_back(g);
                }
                else
                {
                    if (a[1] != a[2] && c == a[2])
                    {
                        g--;
                        result.push_back(g);
                    }
                    else
                        result.push_back(g);
                }
            }
            else
            {
                //p=n
                if (p == n)
                {
                    if (a[n] == a[n - 1] && c == a[n - 1])
                    {
                        g++;
                        result.push_back(g);
                    }
                    else
                    {
                        if (a[n] != a[n - 1] && c == a[n - 1])
                        {
                            g--;
                            result.push_back(g);
                        }
                        else
                            result.push_back(g);
                    }
                }
                //th bat ki
                else
                {
                    //+2
                    if (a[p - 1] == a[p + 1] && a[p - 1] == a[p] && c != a[p])
                    {
                        g += 2;
                        result.push_back(g);
                    }
                    //+1
                    else
                    {
                        if (a[p - 1] != a[p + 1] && (a[p] == a[p + 1] || a[p] == a[p - 1]) && c != a[p + 1] && c != a[p - 1])
                        {
                            g++;
                            result.push_back(g);
                        }
                        //-1
                        else
                        {
                            if (a[p - 1] != a[p + 1] && a[p] != a[p - 1] && a[p] != a[p + 1] && (c == a[p - 1] || c == a[p + 1]))
                            {
                                g--;
                                result.push_back(g);
                            }
                            //-2
                            else
                            {
                                if (a[p - 1] == a[p + 1] && a[p] != a[p + 1] &&c == a[p + 1])
                                {
                                    g-=2;
                                    result.push_back(g);
                                }
                                //+0
                                else result.push_back(g);
                            }
                        }
                    }
                }
            }

        }
        vector<int>::iterator l;
        for (l = result.begin(); l != result.end(); l++)
        {
            cout << *l << endl;
        }
    }
}
