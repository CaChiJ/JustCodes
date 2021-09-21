#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pos;

#define ff first
#define ss second

pos operator-(const pos& a, const pos& b) { return {a.ff-b.ff, a.ss-b.ss}; }

ll ccw(const pos& p, const pos& q) { return (p.ff*q.ss) - (p.ss*q.ff); }
ll ccw(const pos& p, const pos& q, const pos& r) { return ccw(q-p, r-p); }

int main(void) {
    pos p[3];

    for(int i = 0; i < 3; ++i) {
        scanf("%lld %lld", &(p[i].ff), &(p[i].ss));
    }

    ll result = ccw(p[0], p[1], p[2]);
    cout << (result ? result / abs(result) : 0) << endl;

    return 0;
}