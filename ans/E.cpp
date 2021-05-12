#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, d;
    vector<int> a;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        int aTemp;
        scanf("%d", &aTemp);
        a.push_back(aTemp);
    }

    // まずはa[i]+a[j]の計算結果を網羅したvectorであるa2を作る
    // 計算時間はO(n^2)
    int n2 = n * n;
    vector<int> a2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a2.push_back(a[i] + a[j]);
        }
    }

    // 計算時間はO(n^2*log(n))
    sort(a2.begin(), a2.end());

    // a2[i]+a2[j]を計算すればa[i]+a[j]+a[k]+a[l]を網羅できる
    // a2[i]+a2[j]の計算は300点の場合と同様に高速化できる
    // O(log(n))の計算をn^2回のループで回すので計算時間はO(n^2*log(n))
    long long ret = 0;
    for (int i = 0; i < n2; i++) {
        int key = d - a2[i];

        auto lb = lower_bound(a2.begin(), a2.end(), key);
        auto ub = upper_bound(a2.begin(), a2.end(), key);

        ret += ub - lb;
    }

    printf("%lld\n", ret);

    return 0;
}