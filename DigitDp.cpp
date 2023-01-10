/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
// https://lightoj.com/problem/investigation
#include <bits/stdc++.h>
using namespace std;

#define FIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test   \
    ll ct;     \
    cin >> ct; \
    while (ct--)
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;

ll dp[15][100][100][2];

ll digitDp(ll d, string &limit, ll num, ll sum, ll k, bool tight)
{
    if (d == limit.size())
    {
        if (sum % k == 0 && num % k == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[d][num][sum][tight] != -1)
    {
        return dp[d][num][sum][tight];
    }

    ll ans = 0;

    ll ub = tight ? limit[d] - '0' : 9;

    for (ll dig = 0; dig <= ub; dig++)
    {
        ll t = (num * 10) + dig;
        ans += digitDp(d + 1, limit, t % k, (sum + dig) % k, k, tight & (ub == dig));
    }
    return dp[d][num][sum][tight] = ans;
}
void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;

    if (k > 82)
    {
        cout << 0 << nn;
        return;
    }

    string R = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll x = digitDp(0, R, 0, 0, k, 1);

    memset(dp, -1, sizeof(dp));
    R = to_string(--a);
    ll y = digitDp(0, R, 0, 0, k, 1);

    cout << (x - y) << nn;
}

int main()
{
    FIO;
    //  read;
    //  write;
    ll i = 1;
    test
    {
        cout << "Case " << i++ << ": ";
        solve();
    }
    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
/* Final check before submit :
1. array size or integer overflow,like uninitialised 0 index.
2. Think twice,code once.check all possible counter test case.
3. Be careful about corner case! n=1?k=1? something about 0?
4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?
5. if got WA than remember that you are missing something common.
*** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;
*/
/* IF WA???
1. corner case! n=1?k=1? something about 0?
2. check code(avoid stupid mistake)
3. read the statement again(if there any missing point???)
4. check the idea(check all possible counter test case again!!!)
5. be calm,don't be panic!!!.(***this problem not going to decide your future***)
6. don't waste too much time. move to next problem
*/