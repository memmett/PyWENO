#!/bin/sh

for src in *.c; do
  indent -l100 $src
done

