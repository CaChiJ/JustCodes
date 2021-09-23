#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pos;

#define ff first
#define ss second

pos operator-(const pos &p, const pos &q)
{
    return {p.ff - q.ff, p.ss - q.ss};
}
ll ccw(const pos &p, const pos &q)
{
    return p.ff * q.ss - p.ss * q.ff;
}
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
    scanf("%d", &N);

    pos nodes[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> nodes[i].ff >> nodes[i].ss;
    }

    {
        pos &minElm = *min_element(nodes, nodes + N);
        pos tmp = minElm;
        minElm = nodes[0];
        nodes[0] = tmp;
    }

    sort(nodes + 1, nodes + N, [&](const pos &p, const pos &q)
         {
             ll tmp = ccw(nodes[0], p, q);
             return (tmp ? tmp > 0 : dist(nodes[0], p) < dist(nodes[0], q));
         });

    vector<pos> hull;

    for (auto &x : nodes)
    {
        while (hull.size() > 1 && ccw(hull[hull.size() - 2], hull.back(), x) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(x);
    }

    cout << hull.size() << endl;
    return 0;
}