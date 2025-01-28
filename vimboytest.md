# テストの考え方

## testの準備

```bash
touch outfile
touch infile
touch noright
chmod -rw noright
```

## 必要な環境変数(ある/ない)
```bash
unset PATH
```

## 必要な引数(ある/ない)
```bash
./pipex a1
./pipex a1 a2
./pipex a1 a2 a3
./pipex a1 a2 a3 a4 a5
```

### すべての引数(正しい/正しくない)
#### 1.インプットファイル(正しい/正しくない)
##### 存在(する/しない) 

```bash
./pipex noexsist <cmd> <cmd> outfile
```

- pipex

```bash
valgrind --leak-check=full --trace-children=yes -q ./pipex noexsist "ls -la" cat outfile
```

- pipe
```bash
< noexsist ls -la | cat | cat > outfile
```

- pipex **うまく行かない**
```bash
valgrind --leak-check=full --trace-children=yes -q ./pipex noexsist cat cat outfile
```


- pipe
```bash
< noexsist cat | cat > outfile
```

##### 権限(ある/ない)

```bash
./pipex noright <cmd1> <cmd2> outfile
```

- pipex

```bash
valgrind --leak-check=full --trace-children=yes -q ./pipex noright "ls -la" cat outfile
```

- pipe
```bash
< noright ls -la | cat | cat > outfile
```

- pipex
```bash
valgrind --leak-check=full --trace-children=yes -q ./pipex noright cat cat outfile
```

- pipe
```bash
< noright cat | cat > outfile
```

#### 2. コマンド1
##### 存在(する/しない) 
```bash
./pipex infile <cmd1> <cmd2> <cmd3> outfile
```
- pipex

```bash
valgrind --leak-check=full --trace-children=yes -q ./pipex infile helloworld cat outfile
```

- pipe
```bash
< infile helloworld | cat > outfile
```

##### 権限(ある/ない)

実行ファイルの権限をなくす
```bash
./pipex infile <cmd1> <cmd2> <cmd3> outfile
```

```bash
echo '#include <stdio.h>\nint main(){printf("hello world\\n");;return 0;}' > example.c
gcc example.c
chmod -x a.out
```

- pipex
```bash
./pipex infile "./a.out" cat cat  outfile
```

- pipe

```bash
< infile ./a.out |cat |cat > outfile
```
僕の実装ではaccess関数で、実行できるか、ファイルがあるかを同時に判定しているので、
command not found と表示される。


- pipex
```bash
./pipex infile "./a.out" cat "ls -la"  outfile
```

- pipe

```bash
< infile ./a.out |cat |ls -la  > outfile
```

#### 3. コマンドn
- pipex
```bash
./pipex infile "./a.out" cat cat  outfile
```

- pipe

```bash
< infile ./a.out |cat |cat > outfile
```
僕の実装では`access`関数で、実行できるか、ファイルがあるかを同時に判定しているので、
`command not found `と表示される。

- pipex
```bash
./pipex infile cat "./a.out" "ls -la"  outfile
```

- pipe

```bash
< infile cat | ./a.out | ls -la  > outfile
```

#### 4. アウトプットファイル(正しい/正しくない)
##### 権限(ある/しない)
```bash
./pipex infile <cmd1> <cmd2> noright
```

- pipex

```bash
./pipex infile cat cat noright
```

- pipe

```bash
< infile cat | cat > noright
```