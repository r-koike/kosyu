<script type="text/x-mathjax-config">MathJax.Hub.Config({tex2jax:{inlineMath:[['\$','\$'],['\\(','\\)']],processEscapes:true},CommonHTML: {matchFontHeight:false}});</script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>

# D: 一致探索

$N$個の整数$A_i\ (1\le i\le N)$と$M$個の整数$B_j\ (1\le j\le M)$が与えられます．
$A_1,\ A_2,\ \cdots,\ A_N$のうち$B_j$に一致するものがいくつあるかを$j$行目に出力してください．

### 制約
- $1\le N,\ M\le 5\times 10^5$
- $0\le A_i,\ B_j\le 10^9$
- 入力はすべて整数

---

### 入力
入力は以下の形式で標準入力から与えられます．
> $N\ M$  
> $A_{1}\ A_{2}\ \cdots\ A_{N}$  
> $B_{1}\ B_{2}\ \cdots\ B_{M}$  

### 出力
$j$行目に$B_j$の個数を出力してください．

---

### 入力例1
> 11 3  
> 1 1 1 2 3 4 5 6 7 8 9  
> 4 1 10

### 出力例1
> 1  
> 3  
> 0

$4$は$1$個，$1$は$3$個，$10$は$0$個含まれています．

---

### 入力例2
> 9 3  
> 12345 6 78901 23 45 6 7 89 0  
> 3 78901 6

### 出力例2
> 0  
> 1  
> 2

---

### ヒント
すべての$B_j\ (1\le j\le M)$に対してすべての$A_i\ (1\le i\le N)$をチェックするようなループを作ると，最悪で$NM=10^{10}$回のループが回るため時間がかかってしまいます．
一般に，**ソートされた**データに対してある条件を満たす値を探すというのは二分探索で書くと効率化されます．
C++の標準ライブラリには`vector`というクラスがあり，二分探索で実装された`lower_bound`などの関数を利用できます． 

