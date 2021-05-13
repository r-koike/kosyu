#include <cstdio>

// 階乗計算のためには何桁の整数まで保持すれば十分か
const int MAX_KETA = 200;

// kaijo[i][j]はiの階乗の右から(j+1)個めの数字とする
int kaijo[200][MAX_KETA];

int main() {
    int n;
    scanf("%d", &n);

    // 0の階乗の1桁目は1とする
    kaijo[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        // ここでは(i-1の階乗)×iを計算する
        // そのために，(i-1の階乗)を各桁に分けた物に対して全部にiを掛け，
        // 掛け算の筆算のように加算していく
        for (int j = 0; j < MAX_KETA; j++) {
            // xは何桁になるかわからない
            int x = kaijo[i - 1][j] * i;

            // このkに関するfor文の中身はxの桁数回だけ実行される
            for (int k = 0; x > 0; k++) {
                kaijo[i][j + k] += x % 10;
                x /= 10;

                // kaijoの配列は10以上の数字を保持しないようにする
                x += kaijo[i][j + k] / 10;
                kaijo[i][j + k] %= 10;
            }
        }
    }

    int ret = 0;
    int keta = 0;
    bool zero_padding = true;
    for (int i = MAX_KETA - 1; i >= 0 && keta < 3; i--) {
        // 最初の方はゼロで埋まっているはず(ゼロパディング)なので，
        // 最初に0以外の数字が来るまでスルーする
        if (zero_padding && kaijo[n][i] == 0) {
            continue;
        }
        zero_padding = false;

        ret *= 10;
        ret += kaijo[n][i];
        keta++;
    }

    printf("%d\n", ret);

    return 0;
}