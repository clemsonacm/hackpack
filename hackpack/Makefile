hotfix:
	-rm -rf build
	-mkdir build
	latexmk -pdf
	-mv *.aux build
	-mv *.blg build
	-mv *.fdb_latexmk build
	-mv *.idx build
	-mv *.ilg build
	-mv *.ind build
	-mv *.log build
	-mv *.out build
	-mv *.pdf build
	-mv *.toc build
	-mv *.fls build

all:
	latexmk -pdf -auxdir=build -outdir=build

clean:
	-latexmk -c -outdir=build
