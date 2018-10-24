#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    map <string, int> mi;
    int i = 0;
    vector <int> sz(N), base(N), D(N);
    vector <vector <int> > Lb(N), Ub(N);

    while(N--) ///Inputting
    {
        string s;
        cin >> s;
        mi[s] = i; ///Mapping
        cin >> base[i] >> sz[i] >> D[i];

        for(int j = 0; j < D[i]; j++) ///Getting lower and upper bounds
        {
            int a, b;
            cin >> a >> b;
            Lb[i].push_back(a);
            Ub[i].push_back(b);
        }

        i++;
    }

    while(Q--)
    {
        string s;
        cin >> s;
        int idx = mi[s]; ///Taking map address of s in idx
        addrs = 0;
        int Dim = D[idx];
        vector <int> v(Dim);

        for(int j = 0; j < Dim; j++) ///Taking dimenstions' index
            cin >> v[j];

        int Ci = sz[idx]; ///Calculation of Ci initialised by size of that query

        for(int j = Dim - 1; j >= 0; j--) ///Have to start from last address
        {
            int Di = v[j] - Lb[idx][j]; /// Taking actual 0 based index
            addrs += (Di * Ci); /// adding dimensions' size
            Ci *= (Ub[idx][j] - Lb[idx][j] + 1); ///Updating Ci for next addition
        }

        ///Outputting
        cout << s << "[" << v[0];

        for(int j = 1; j < Dim; j++)
            cout << ", " << v[j];

        cout << "] = " << base[idx] + addrs << endl;
    }

    return 0;
}
