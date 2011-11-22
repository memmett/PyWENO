
all: profile1

reconstruct.c: reconstruct.py
	python reconstruct.py > reconstruct.c

profile1: reconstruct.c main.c
	gcc -std=c99 -pg -O3 $^ -o $@ -lm
