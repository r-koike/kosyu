#include <cstdio>

int main() {
    // aの配列はn,mの最大値に対して余分に用意しておく
    int n, m, a[110][110];

    // 入力
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 計算と出力
    for (int i = 0; i < n; i++) {
        // これは新しいループに入るごとに0で初期化される
        int ret = 0;

        // 総和を計算する
        for (int j = 0; j < m; j++) {
            ret += a[i][j];
        }

        // 出力する
        printf("%d\n", ret);
    }

    return 0;
}