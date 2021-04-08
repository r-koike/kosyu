## 問題
[リンク](https://r-koike.github.io/kosyu/)

## 動作環境
- Windows 10
- PowerShell (5.1.21343.1000で動作確認)
- g++ (9.2.0で動作確認)

## 準備
### エディタのインストール
お好きなものを各自でどうぞ．
何もわからなければVSCodeがおすすめ．

### GCCのインストール
PowerShellを開き，`g++ --version`をやっていい感じのものが表示されれば準備完了．
表示されなければMinGWなどでGNU C++ Compilerをインストールし，環境変数Pathに登録する．
[このページ](https://qiita.com/rkoike/items/26ee37e2107a0dac88b8)の「コンパイラ管理ソフトMinGWをインストールする」から「gccを環境変数Pathに登録する」の手順が対応する．

### PowerShellの実行ポリシーの変更
PowerShellはセキュリティ上の問題によりデフォルトで全てのスクリプトの実行を制限している．
.ps1ファイルを実行するために，「ローカルファイルは全て実行可能」という設定に変える([参考](https://docs.microsoft.com/ja-jp/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.1#remotesigned))．
上記を理解したうえでPowerShellを**管理者権限で**開き，`Set-ExecutionPolicy RemoteSigned`を行う．

### リポジトリのclone
[このリンク](https://github.com/r-koike/kosyu/archive/refs/heads/master.zip)を踏めば最新のもののZIPファイルが手に入る．
自分のPCで展開しておく．
`git clone`してもいい．


## 動作確認
1. PowerShellを開く．
2. `cd [リポジトリを展開した場所]`とする．
3. `.\benchmark.ps1`とすれば高速・低速の2種類のベンチマークが始まる．
   - 高速な方は100ms程度，低速な方は1500ms程度の時間がかかるはず．
   - 2種類のベンチマークでほとんど変わらない結果が出ていたらなにかがおかしい．
4. 正常に完了したら`/res/bench/time_limit.txt`が作成される．それが自分のPCにおける実行制限時間(秒)．

