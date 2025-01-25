# test

## 正常なケース

```bash
./pipex infile cat cat outfile
```

```
cat (in -> out)
grep something (in -> out)
ls (-> out)
sleep ()
```

### infileが不正

```bash
./pipex <存在しないファイルのパス> cat cat outfile
```

```bash
./pipex <読み込み権限のないファイルのパス> cat cat outfile
```

### cmd1

```bash
./pipex infile <存在しないコマンド> cat outfile
```

```bash
./pipex infile <実行権限のないコマンド> cat outfile
```

### cmd2

```bash
./pipex infile cat <存在しないコマンド>  outfile
```

```bash
./pipex infile cat <実行権限のないコマンド> outfile
```

### outfileが不正

```bash
./pipex infile cat cat <書き込み権限がないファイル>
```
