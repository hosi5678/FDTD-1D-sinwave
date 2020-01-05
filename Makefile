CC=gcc
CFLAGS = -g -Wall -std=gnu99 -pipe -march=native -funroll-loops -fforce-addr -O2 -pipe -msse -msse2 -msse3 -m3dnow -mmmx -mfpmath=sse
LDLIBS = -lm
OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))
TARGET =main

ifeq ($(OS),Windows_NT)
	RM=del
else
	RM=rm -f
endif

# $@:ターゲットファイル名
# $<:最初の依存するファイルの名前
# $?:ターゲットより新しいすべての依存するファイル名
# $^:すべての依存するファイルの名前

# substitute 取り替える. ()と{}は同義
# -march=native: 自動的にそのアーキテクチャにそったオプションをつける
# -funroll-loops: ループの展開を行います。バイナリサイズは増える可能性がある
# -fforce-addr: ある計算をメモリ上ではなくCPUのレジスタにコピーして行うようにする
# -O2: この他に-O0(最適化無し), -O1, -O3がありこの数字の順に強い最適化をかける
# -msse -msse2 -msse3 -m3dnow -mmmx -mfpmath=sse: CPUの拡張命令セットを使うようにする

# -g 実行ファイルにデバッグ用の情報を埋め込む 

# -l リンクするオブジェクトライブラリを指定
#［例］ gcc -o prog prog.c -lm
# コンパイル時に、数学関数ライブラリ(libm.a)をリンクする

# -Wall 文法チェックのために、ワーニング(warning、コンパイル時の警告)をすべて表示
#［例］ gcc -Wall -o prog prog.c

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@
	./$(TARGET)
	$(RM) *.o

.PHONY : clean
clean :
	$(RM) main *.o *.exe

