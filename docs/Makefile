#
# Makefile for PyWENO documentation
#

SPHINXBUILD = sphinx-build
SPHINXOPTS  = -d _doctrees
SPHINXGHPAGES = ~/bin/sphinx-to-github

html:
	pdflatex weno.tex
	pdflatex weno.tex
	$(SPHINXBUILD) -b html $(SPHINXOPTS) . _build
	rm -rf _ghpages/*
	cp -R _build/* _ghpages/
	cd _ghpages && $(SPHINXGHPAGES)

all: html

.PHONY: html
