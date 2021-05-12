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

    // 計算時間はO(n*log(n))
    sort(a.begin(), a.end());

    // 4つめのループはa[l]=d-(a[i]+a[j]+a[k])を満たすlが存在するかを探索することに置き換えられる
    // O(log(n))の計算を3重ループで回すので計算時間はO(n^3*log(n))
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int key = d - (a[i] + a[j] + a[k]);

                auto lb = lower_bound(a.begin(), a.end(), key);
                auto ub = upper_bound(a.begin(), a.end(), key);

                ret += ub - lb;
            }
        }
    }

    printf("%lld\n", ret);

    return 0;
}