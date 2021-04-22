#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<tuple<int, int, int>> vt;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i, x) for (int i = 0; i < x; i++)
#define rep1(i, x) for (int i = 1; i <= x; i++)
#define srep(i, s, x) for (int i = s; i < x; i++)
#define rrep(i, x) for (int i = x - 1; i >= 0; i--)
#define rrep1(i, x) for (int i = x; i > 0; i--)
#define rsrep(i, s, x) for (int i = x - 1; i >= s; i--)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define sor(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define lb(vec, a) lower_bound(vec.begin(), vec.end(), a)
#define ub(vec, a) upper_bound(vec.begin(), vec.end(), a)
#define uniq(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define mp1(a, b, c) P1(a, P(b, c))

double out_doubles[10], ans_doubles[10];

signed main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Invalid number of args" << endl;
        return 1;
    }

    string out_fullname = argv[1];
    string ans_fullname = argv[2];
    // cout << out_fullname << endl;
    // cout << ans_fullname << endl;

    ifstream out_ifs(out_fullname, ios::in);
    ifstream ans_ifs(ans_fullname, ios::in);
    if (!out_ifs || !ans_ifs) {
        cout << "Error: file not opened." << endl;
        return 1;
    }

    rep(i, 3) {
        out_ifs >> out_doubles[i];
        ans_ifs >> ans_doubles[i];
        if (out_doubles[i] != ans_doubles[i]) {
            cout << "WA" << endl;
            return 1;
        }
    }

    /* --------------------------------- */
    cout << "AC" << endl;
    return 0;
};