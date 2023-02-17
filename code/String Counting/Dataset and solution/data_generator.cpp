#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("./input/sample_input.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)

#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-6
#define spc          " "
#define nn           "\n"

const double pi = 2 * acos(0.0);
typedef long long int          ll;
typedef unsigned long long  ull;
typedef long double         ld;

// this gives the seed for randomness, somehow from the timecount [I do not know the rest]
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

// The random generator function
// It returns a random number in the range of [a,b]
template <typename T> T random(T a, T b){
    return a + (rng() % (b - a + 1));
}

// geenrates a string consisting of random lowercase latin letters
string GenerateLowerCase(int maxlen) {
    int len = random(maxlen-2 , maxlen);
    string s;
    for (int i = 0; i < len; i++) {
        int r = random(0 , 25);
        s.push_back(r + 'a');
    }
    return s;
}

const int mxn = 1e5;

void generate(){
    // write the generator code here
    // Example:
    // int x = random(1,10) // gives 'x' a random value from 1 to 10 [inclusive]
}

int main() {
    // Fin;
    Fout;
    FasterIO;
    generate();
    return 0;
}
