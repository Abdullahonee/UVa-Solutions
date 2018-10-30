#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        vector <int> Fv(n), Rv(n);
        vector <bool> FvChk(n, false), RvChk(n, false);
        vector <vector <int> > table(n, vector <int> (n, 0));

        for(int i = 0; i < n; i++)
            cin >> Fv[i];

        for(int i = 0; i < n; i++)
            cin >> Rv[i];

        ///Positioning common value of Fv and Rv
        for(int i = 0; i < n; i++)
        {
            int pos;
            bool flag = true;

            for(int j = 0; j < n; j++)
            {
                if(flag)
                {
                    if(Rv[j] >= Fv[i])
                        pos = j, flag = false;
                }

                else
                {
                    if(Rv[j] < Rv[pos] && Rv[j] >= Fv[i])
                        pos = j;

                    else if(Rv[j] == Rv[pos] && !RvChk[j])
                        pos = j;
                }
            }

            table[i][pos] = Fv[i];
            FvChk[i] = true;

            if(Fv[i] == Rv[pos])
                RvChk[pos] = true;
        }

        ///Positioning rest values of Rv
        for(int i = 0; i < n; i++)
        {
            if(!RvChk[i])
            {
                int pos;
                bool flag = true;

                for(int j = 0; j < n; j++)
                {
                    if(flag)
                    {
                        if(Fv[j] >= Rv[i])
                            pos = j, flag = false;
                    }

                    else
                    {
                        if(Fv[j] < Fv[pos] && Fv[j] >= Rv[i])
                            pos = j;

                        else if(Fv[pos] == Fv[j] && !FvChk[j])
                            pos = j;
                    }
                }

                table[pos][i] = Rv[i];
                RvChk[i] = true;
            }
        }

        int cmin = 0, cmax = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cmin += table[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                table[i][j] = min(Fv[i], Rv[j]);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cmax += table[i][j];

        cout << "Matty needs at least "<< cmin << \
        " blocks, and can add at most " << cmax - cmin << " extra blocks.\n";
    }

    return 0;
}
