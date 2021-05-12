#include <algorithm>
#include <cmath>
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    // 階乗のlogをdouble型で計算する
    double log_kaijo = 0;
    for (int i = 1; i <= n; i++) {
        log_kaijo += log10(i);
    }

    // 階乗の仮数部と指数部をそれぞれdouble型，int型で計算する
    double base_kaijo = pow(10, log_kaijo - (int)log_kaijo);
    int index_kaijo = (int)log_kaijo;
    for (int i = 0; i < std::min(index_kaijo, 2); i++) {
        base_kaijo *= 10;
    }

    // double型をint型へ丸めこむ
    // base_kaijoは119.99999999999などになる可能性があるので，
    // 微小数値を足してから暗黙的にint型に変換する
    int a = base_kaijo + 0.0000000001;
    printf("%d\n", a);

    return 0;
}
