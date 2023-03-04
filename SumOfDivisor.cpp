#include <iostream>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

/** return The sum of all numbers in [start, end] mod MOD. */
ll total_sum(ll start, ll end)
{
    return (
        (((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) * TWO_MOD_INV % MOD);
}

int main()
{
    ll n;
    cin >> n;

    ll total = 0;
    ll at = 1;

    while (at <= n)
    {
        ll add_amt = n / at; // Our divisor to process
        // The largest number that still has the same value of q
        ll last_same = n / add_amt;

        total = (total + add_amt * total_sum(at, last_same)) % MOD;
        at = last_same + 1;
    }

    cout << total << endl;
}