#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    scanf("%d", &N);

    ll result;

    {
        int cnt = 0;
        ll an1 = 1; // f(n-3)
        ll an2 = 1; // f(n-2)
        ll an3 = 1; // f(n-1)

        for (int i = 4; i <= N; ++i)
        {

            ll tmp = an3 + an1;
            an1 = an2;
            an2 = an3;
            an3 = tmp;
            cnt++;
        }

        result = an3;
    }

    printf("%lld\n", result);
    return 0;
}