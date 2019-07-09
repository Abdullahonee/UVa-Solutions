#include <bits/stdc++.h>
using namespace std;

#define fi freopen("i.txt", "r", stdin)
#define fo freopen("o.txt", "w", stdout)
#define SIO ios_base :: sync_with_stdio(false); cin.tie(0)
#define fs first
#define sc second
#define cn(a) cin >> a
#define cn2(a, b) cin >> a >> b
#define cn3(a, b, c) cin >> a >> b >> c
#define cn4(a, b, c, d) cin >> a >> b >> c >> d
#define sf(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define sfl(a) scanf("%lld", &a)
#define sfl2(a, b) scanf("%lld %lld", &a, &b)
#define sfl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define sfl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define pnl() putchar('\n')
#define fli(i, a, b, c) for(int i = a; i < b; i += c)
#define flie(i, a, b, c) for(int i = a; i <= b; i += c)
#define fls(i, a, b) for(int i = a; i < b; i++)
#define flse(i, a, b) for(int i = a; i <= b; i++)
#define fl(i, n) fls(i, 0, n)
#define fle(i, n) flse(i, 1, n)
#define ll long long
#define ld long double
#define vi vector <int>
#define vll vector <ll>
#define ii pair <int, int>
#define pll pair <ll, ll>
#define iii pair <int, pair <int, int> >
#define lll pair <ll, pair <ll, ll> >
#define vii vector <ii>
#define vpll vector <pll>
#define vlll vector <lll>
#define pb push_back
#define ins insert
#define fr front
#define mp make_pair
#define PI acos(-1.0)
#define INF 10000000
#define LINF 1000000000000
#define piiii pair <ii, ii>
#define sq(a) a * a
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define gc() getchar()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchgc(x) cout << (#x) << " is " << (x) << endl; gc()

struct node
{
    int m, s, e;
};

int main()
{
    SIO;
    int tc = 0, N, M;

    while(cin >> N >> M, N | M)
    {
        vector <vector <int> > msgs(N + 1, vector <int> ());
        vector <int> sN(1);

        for(int i = 1; i <= N; i++)
        {
            int n;
            cin >> n;
            sN.push_back(n);
        }

        vector <node> sM(1);

        for(int i = 1; i <= M; i++)
        {
            int m, s, e;
            cin >> m >> s >> e;
            sM.push_back({m, s, e});
        }

        vector <int> perN;

        for(int i = 1; i <= N; i++)
            perN.push_back(i);

        int minBufByte = INT_MAX;

        do
        {
            for(int i = 1; i <= N; i++)
                msgs[i].assign(sN[i] + 1, 0);

            int cur = 0;
            int maxByte = INT_MIN, nowByte = 0;
            int serial = perN[cur];

            for(int i = 1; i <= M; i++)
            {
                int m = sM[i].m;
                int s = sM[i].s;
                int e = sM[i].e;

                for(int j = s; j <= e; j++)
                {
                    msgs[m][j] = 1;
                    nowByte++;
                }

                if(m == serial)
                {
                    while(1)
                    {
                        for(int j = 1, sz = msgs[serial].size(); j < sz; j++)
                        {
                            if(msgs[serial][j] == 1)
                            {
                                msgs[serial][j] = 2;
                                nowByte--;
                            }

                            else if(msgs[serial][j] == 0)
                                break;
                        }

                        if(msgs[serial][msgs[serial].size() - 1] == 2 && cur + 1 < perN.size())
                            serial = perN[++cur];

                        else
                            break;
                    }
                }

                maxByte = max(maxByte, nowByte);
            }

            minBufByte = min(maxByte, minBufByte);
        }
        while(next_permutation(all(perN)));

        cout << "Case " << ++tc << ": " << minBufByte << "\n\n";
    }

    return 0;
}
