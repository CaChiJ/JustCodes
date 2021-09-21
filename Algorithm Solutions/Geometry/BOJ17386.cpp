#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pos;

#define ff first
#define ss second

pos operator-(const pos& a, const pos& b) { return {a.ff-b.ff, a.ss-b.ss}; }

ll ccw(const pos& p, const pos& q) { return p.ff*q.ss - p.ss*q.ff; }
ll ccw(const pos& p, const pos& q, const pos& r) { return ccw(q-p, r-p); }
ll _ccw(const pos& p, const pos& q, const pos& r) {
    ll tmp = ccw(p, q, r);
    return tmp ? tmp / abs(tmp) : 0;
}

void swap(pos& a, pos& b) {
    pos tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    pos a1, a2, b1, b2;
    scanf("%lld %lld %lld %lld", &(a1.ff), &(a1.ss), &(a2.ff), &(a2.ss));
    scanf("%lld %lld %lld %lld", &(b1.ff), &(b1.ss), &(b2.ff), &(b2.ss));
    
    ll ccw1 = _ccw(a1, a2, b1) * _ccw(a1, a2, b2);
    ll ccw2 = _ccw(b1, b2, a1) * _ccw(b1, b2, a2);
    
    if(ccw1 == 0 && ccw2 == 0) {
        if(a1 > a2) {
            swap(a1, a2);
        }
        
        if(b1 > b2) {
            swap(b1, b2);
        }
        
        if(a1 <= b2 && b1 <= a2) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    } else if(ccw1 <= 0 && ccw2 <= 0) {
        cout << "1\n"; 
    } else {
        cout << "0\n";
    }
    
    return 0;
}