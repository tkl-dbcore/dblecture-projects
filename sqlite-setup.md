# 初年次ゼミナール用補足資料
- 2022年度 初年次ゼミナール理科 火曜１限 ビッグデータを扱うソフトウェア技術「データベース」を実践する

## SQLite準備するためのコマンド手順一覧

SQLite をインストール

```bash
sudo apt-get install sqlite3
```

SQLite の表示を見やすくするツールをインストール

```bash
sudo pip3 install litecli
```

ディスク容量を拡張するおまじない

```bash
curl -L http://bit.ly/disk-resize | bash
```

ディスク容量を確認する
```bash
df -h
```

IMDbデータベースの zipファイルを取得

```bash
wget https://sqlite-imdb.s3-ap-northeast-1.amazonaws.com/sqlite-imdb.zip
```

zipファイルを展開
```bash
unzip sqlite-imdb.zip
```

展開されたファイルを確認
```
ls
```

SQLite を起動するコマンド                      

```
litecli imdb.sqlite3
```
