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
{% raw %}
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
{% endraw %}
```

---

### 基となるプログラム


---

### ヒント
場合分けのゴリ押しで解こうとはしないでください．
オーバーロードやテンプレートなどのC++の機能が使えます．



