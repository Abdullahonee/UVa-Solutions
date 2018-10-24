#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, P = 0;
    cin >> M;

    while(M--)
    {
        int N, K;
        cin >> N >> K;
        vector <bool> flag(N, false);

        while(K--)
        {
            int n;
            cin >> n;
            vector <int> L(n), R(n);

            for(int i = 0; i < n; i++)
                cin >> L[i];

            for(int i = 0; i < n; i++)
                cin >> R[i];

            string s;
            cin >> s;

            if(s == "=")
            {
                for(int i = 0; i < n; i++)
                   flag[L[i] - 1] = true;

                for(int i = 0; i < n; i++)
                   flag[R[i] - 1] = true;
            }
        }

        int Count = 0;

        for(int i = 0; i < N; i++)
            if(!flag[i])
                Count++;

        if(P)
            cout << endl;

        if(Count == 1)
        {
            for(int i = 0; i < N; i++)
                if(!flag[i])
                {
                    cout << i + 1 << endl;
                    break;
                }

        }

        else
            cout << 0 << endl;

        P = 1;
    }

    return 0;
}
