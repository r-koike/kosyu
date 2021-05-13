#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int b[1010101];

int main() {
    // aは配列ではなくvectorとして用意する
    vector<int> a;
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int temp_a;
        scanf("%d", &temp_a);
        a.push_back(temp_a);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    // 計算時間はO(nlog(n))
    sort(a.begin(), a.end());

    // 計算時間はO(mlog(n))
    for (int j = 0; j < m; j++) {
        int key = b[j];

        // 計算時間はO(log(n))
        auto lb = lower_bound(a.begin(), a.end(), key);

        // 計算時間はO(log(n))
        auto ub = upper_bound(a.begin(), a.end(), key);

        printf("%d\n", ub - lb);
    }

    return 0;
}