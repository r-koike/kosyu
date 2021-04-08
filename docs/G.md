<script type="text/x-mathjax-config">MathJax.Hub.Config({tex2jax:{inlineMath:[['\$','\$'],['\\(','\\)']],processEscapes:true},CommonHTML: {matchFontHeight:false}});</script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>

# G: テンプレート

決められた文字列を出力してください．
**ただし，後述のプログラムの指定した部分だけを編集し，回答してください．**
それ以外の部分を編集することは(ジャッジは通りますが)認められません．

---

### 入力
入力はありません．

### 出力
以下の文字列を出力してください．
```
*-----  
i:  
777  
*-----  
x1, x2, x3, x4, x5:  
1  
2  
3  
4  
5  
*-----  
str, p:  
"hello"  
(0, 1)  
*-----  
vec, vec_str, vec_pair:  
{0, 1, 2, 3}  
{"hello", "world", "!"}  
{(0, 1), (2, 3), (4, 5)}  
*-----  
pair_vecvec:  
({0, 1, 2, 3}, {4, 5, 6, 7})  
*-----  
vec_pair_vecvec:  
{({0}, {1, 2}), ({3}, {}), ({4}, {5})}  
*-----  
vec_vec_vec:  
{{{0}, {1, 2}}, {{3}, {4}, {5, 6}}, {{}}}
```

---

### 基となるプログラム

```
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/* ↓ここを編集する． */

/* ↑ここを編集する． */

int main() {
    int i = 777;
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    string str = "hello";
    pair<int, int> p = {0, 1};
    vector<int> vec = {0, 1, 2, 3};
    vector<string> vec_str = {"hello", "world", "!"};
    vector<pair<int, int>> vec_pair = {{0, 1}, {2, 3}, {4, 5}};
    pair<vector<int>, vector<int>> pair_vecvec = {{0, 1, 2, 3}, {4, 5, 6, 7}};
    vector<pair<vector<int>, vector<int>>> vec_pair_vecvec = {
        {{0}, {1, 2}}, {{3}, {}}, {{4}, {5}}};
    vector<vector<vector<int>>> vec_vec_vec = {{{0}, {1, 2}}, {{3}, {4}, {5, 6}}, {{}}};

    disp(i);
    disp(x1, x2, x3, x4, x5);
    disp(str, p);
    disp(vec, vec_str, vec_pair);
    disp(pair_vecvec);
    disp(vec_pair_vecvec);
    disp(vec_vec_vec);

    return 0;
};
```

---

### ヒント
場合分けのゴリ押しで解こうとはしないでください．
オーバーロードやテンプレートなどのC++の機能が使えます．



