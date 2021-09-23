#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pos;

#define ff first
#define ss second

pos operator-(const pos &p, const pos &q)
{
    return {p.ff - q.ff, p.ss - q.ss};
}
ll ccw(const pos &p, const pos &q) { return p.ff * q.ss - p.ss * q.ff; }
ll ccw(const pos &p, const pos &q, const pos &r) { return ccw(q - p, r - p); }
ll _ccw(const pos &p, const pos &q, const pos &r)
{
    ll result = ccw(p, q, r);
    return result ? result / abs(result) : 0;
}
ll dist(const pos &p, const pos &q) { return (p.ff - q.ff) * (p.ff - q.ff) + (p.ss - q.ss) * (p.ss - q.ss); }

int main(void)
{
    int N;
    pos prison;
    scanf("%d %lld %lld", &N, &prison.ff, &prison.ss);
    pos pillars[N];

    for (int i = 0; i < N; ++i)
    {
        scanf("%lld %lld", &pillars[i].ff, &pillars[i].ss);
    }

    int result = 0;

    {
        bool isInclude = true;

        do
        {
            result++;

            if (N == 0)
            {
                break;
            }

            vector<pair<pos, int>> hull;
            int isConnected[N];
            fill_n(isConnected, N, false);

            {
                pos *minE = min_element(pillars, pillars + N);
                pos tmp = *minE;
                *minE = pillars[0];
                pillars[0] = tmp;
            }

            sort(pillars + 1, pillars + N, [&](const pos &a, const pos &b)
                 {
                     ll c = ccw(pillars[0], a, b);
                     return (c ? c > 0 : dist(pillars[0], a) < dist(pillars[0], b));
                 });

            for (int i = 0; i < N; ++i)
            {
                while (hull.size() > 1 && ccw(hull[hull.size() - 2].ff, hull.back().ff, pillars[i]) <= 0)
                {
                    hull.pop_back();
                }

                hull.push_back({pillars[i], i});
            }

            for (int i = 0; i < hull.size(); ++i)
            {
                isConnected[hull[i].ss] = true;
                ll c = ccw(hull[i].ff, hull[(i + 1) % hull.size()].ff, prison);

                if (c <= 0)
                {
                    isInclude = false;
                    break;
                }
            }

            if (hull.size() == 0)
            {
                isInclude = false;
            }

            int idx = 0;

            for (int i = 0; i < N; ++i)
            {
                if (isConnected[i])
                {
                    continue;
                }

                pillars[idx] = pillars[i];
                idx++;
            }

            N = idx;
        } while (isInclude);

        result--;
    }

    printf("%d\n", result);
    return 0;
}