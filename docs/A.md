<script type="text/x-mathjax-config">MathJax.Hub.Config({tex2jax:{inlineMath:[['\$','\$'],['\\(','\\)']],processEscapes:true},CommonHTML: {matchFontHeight:false}});</script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>

# A: 合計

$N\times M$個の整数$A_{ij}\ (1\le i\le N,\ 1\le j\le M)$が与えられます．
$i$行目に$\sum_{j=1}^M A_{ij}$を出力するプログラムを作成してください．

### 制約
- $1\le N,\ M\le 100$
- $0\le A_{ij}\le 10^5$
- 入力は全て整数

---

### 入力
入力は以下の形式で標準入力から与えられます．
> $N\ M$  
> $A_{11}\ A_{12}\ \cdots\ A_{1M}$  
> $\vdots$  
> $A_{N1}\ A_{N2}\ \cdots\ A_{NM}$  

### 出力
$i$行目に$\sum_{j=1}^M A_{ij}$を出力してください．

---

### 入力例1
> 1 5  
> 1 2 3 4 5  

### 出力例1
> 15  

$1+2+3+4+5=15$です．

---

### 入力例2
> 3 4  
> 0 0 0 0  
> 12 34 56 7890  
> 100000 100000 100000 100000  

### 出力例2
> 0  
> 7992  
> 400000

---

### ヒント
例えば次のプログラムで標準入力を受け取り，$i$行目に$A_{i1}$を出力できます．
ただし$A_{ij}$=`a[i-1][j-1]`であり，問題文とプログラム上で添字がずれていることに注意してください．

```
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
```



