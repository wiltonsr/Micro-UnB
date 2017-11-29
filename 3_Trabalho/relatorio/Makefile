all:
	pdflatex relatorio.tex
	-bibtex relatorio.aux
	pdflatex relatorio.tex
	pdflatex relatorio.tex
	rm -rf *.aux *.bbl *.blg *.dvi *.log
	mv relatorio.pdf ../relatorio_final.pdf
