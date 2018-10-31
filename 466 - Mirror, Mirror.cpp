#include <bits/stdc++.h>
using namespace std;
#define Grid vector< vector <char> >
#define new_Grid(n) vector< vector <char> > (n, vector <char> (n))

void rotate90(Grid &G)
{
    int n = G.size();

    for(int i = 0; i < n / 2; i++)
    {
        int idx = n - 1 - i;

        for(int j = i; j < idx; j++)
        {
            int jdx = n - 1 - j;
            char temp = G[i][j];
            G[i][j] = G[jdx][i];
            G[jdx][i] = G[idx][jdx];
            G[idx][jdx] = G[j][idx];
            G[j][idx] = temp;
        }
    }
}

void reflect(Grid &G)
{
    int n = G.size();

    for(int i = 0; i < n / 2; i++)
    {
        int idx = n - 1 - i;

        for(int j = 0; j < n; j++)
            swap(G[i][j], G[idx][j]);
    }
}

bool comp(Grid &a, Grid &b)
{
    int n = a.size();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[i][j])
                return false;

    return true;
}

void solve(int n, int &tc)
{
    Grid G = new_Grid(n), F = new_Grid(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> G[i][j];

        cin.get();

        for(int j = 0; j < n; j++)
            cin >> F[i][j];
    }

    if(comp(G, F))
    {
        cout << "Pattern " << ++tc << " was preserved.\n";
        return;
    }

    int val = 0;

    for(int i = 0; i < 3; i++)
    {
        rotate90(G);
        val += 90;

        if(comp(G, F))
        {
            cout << "Pattern " << ++tc << \
            " was rotated " << val << " degrees.\n";
            return;
        }
    }

    rotate90(G);
    reflect(G);

    if(comp(G, F))
    {
        cout << "Pattern " << ++tc << " was reflected vertically.\n";
        return;
    }

    val = 0;

    for(int i = 0; i < 3; i++)
    {
        rotate90(G);
        val += 90;

        if(comp(G, F))
        {
            cout << "Pattern " << ++tc << \
            " was reflected vertically and rotated " << val << " degrees.\n";
            return;
        }
    }

    cout << "Pattern " << ++tc << " was improperly transformed.\n";
    return;
}

int main()
{
    int n, tc = 0;

    while(cin >> n)
        solve(n, tc);

    return 0;
}
