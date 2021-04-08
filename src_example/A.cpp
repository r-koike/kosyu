#include <cstdio>
int main() {
    // aの配列はn,mの最大値に対して余分に用意しておきます．
    int n, m, a[110][110];

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        // 1列目を出力します．
        printf("%d\n", a[i][0]);

    return 0;
}