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

    // 4重ループをまわすので計算時間はO(n^4)
    int ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < n; l++)
                    if (a[i] + a[j] + a[k] + a[l] == d)
                        ret++;

    printf("%d\n", ret);

    return 0;
}