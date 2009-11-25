#
# Makefile for PyWENO documentation
#

SPHINXBUILD = sphinx-build
SPHINXOPTS  = -d _doctrees
SPHINXGHPAGES = ~/bin/sphinx-to-github

html:
	$(SPHINXBUILD) -b html $(SPHINXOPTS) . _build
	rm -rf _ghpages/*
	cp -R _build/* _ghpages/
	cd _ghpages && $(SPHINXGHPAGES)

#weno.pdf:
#	pdflatex weno.tex
#	pdflatex weno.tex


all: html

.PHONY: html
