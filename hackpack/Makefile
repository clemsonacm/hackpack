OUTDIR = build
AUXFILES = *.aux *.blg *.fdb_latexmk *.fls *.idx *.ilg *.ind *.log *.out *.pdf *.toc
HAS_OUTDIR = $(shell latexmk --help | grep -- "-output-directory" | wc -l)

hotfix:
	-rm -rf $(OUTDIR)
	-mkdir $(OUTDIR)
	-latexmk -pdf
	-mv $(AUXFILES) $(OUTDIR)

hackpack hackpackpp:
# Build the PDF and auxiliary files into the OUTDIR
ifeq ($(HAS_OUTDIR), 1)
	@echo "Woah! You have that option!"
else
	@echo "You don't have that option."
endif

all:
	latexmk -pdf -auxdir=build -outdir=build

clean:
	-latexmk -c -outdir=build
