<script type="text/x-mathjax-config">MathJax.Hub.Config({tex2jax:{inlineMath:[['\$','\$'],['\\(','\\)']],processEscapes:true},CommonHTML: {matchFontHeight:false}});</script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>

# F: クラス

次の操作と終了条件を考えます．

**操作** 
1. 次のいずれかの操作を行う
  - 対象の数字が奇数なら，$3$を掛けて$1$を加える
  - 対象の数字が偶数なら，$2$で割る
2. 現在の数字を標準出力する

**終了条件** 
- 対象の数字が$1$なら終了する
- 対象の数字がすでに標準出力されたものであれば終了する

$N$個の整数$X_i\ (1\le i\le N)$が与えられます．
まず$X_1$に対して，$X_1$を出力し，**終了条件**を満たすまで**操作**を行ってください．
次に$X_2,\ \cdots,\ X_N$に対してもそれぞれ順番に同様の処理を行ってください．
**ただし，後述のプログラムの指定した部分だけを編集し，回答してください．**
それ以外の部分を編集することは(ジャッジは通りますが)認められません．

### 制約
- $1\le N\le 10^4$
- $0\le X_i\le 10^4$
- 入力は全て整数
- 上記制約のもとで操作対象の数字は$50000000$を超えないことが保証される

---

### 入力
入力は以下の形式で標準入力から与えられます．
> $N$  
> $X_{1}$  
> $\vdots$  
> $X_{N}$  

### 出力
問題文の通りに出力してください．
ただし出力のたびに改行を行ってください．

---

### 入力例1
> 2  
> 5  
> 4

### 出力例1
> 5  
> 16  
> 8  
> 4  
> 2  
> 1  
> 4

まずは$5$に対して，

$$5\times 3 + 1 = 16$$

$$16/2 = 8$$

$$8/2 = 4$$

$$4/2 = 2$$

$$2/2 = 1$$

です．
次に$4$に対して，$4$を出力します．
しかし$4$は$5$に対する操作の中で既に出力されているため，**終了条件**を満たします．
よってこの時点で$4$に対する操作は終了します．

---

### 基となるプログラム

```
#include <cstdio>
using namespace std;

const int MAX_X = 50005000;

class Collatz {
  private:
    /* ↓ここを編集する． */

    /* ↑ここを編集する． */

  public:
    Collatz(int x);
    int step();
    bool shouldProceed();
    void leaveFootprint();
    int getX();
};

/* ↓ここを編集する． */

/* ↑ここを編集する． */

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        Collatz collatz(x);
        printf("%d\n", collatz.getX());
        while (collatz.shouldProceed()) {
            collatz.leaveFootprint();
            printf("%d\n", collatz.step());
        }
    }

    return 0;
}
```



