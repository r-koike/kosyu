#include <cmath>
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    // 階乗をdouble型で計算する
    double kaijo = 1;
    for (int i = 1; i <= n; i++) {
        kaijo *= i;
    }

    // kaijoの左から3桁を求める
    // adが3桁よりも大きい限りは続行する
    double double_a = kaijo;
    while (floor(log10(double_a) + 1) > 3) {
        double_a /= 10;
    }

    // double型をint型へ暗黙に変換するとき小数点以下は切り捨てられる
    int a = double_a;
    printf("%d\n", a);

    return 0;
}
