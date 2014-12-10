OUTDIR = build
AUXFILES = *.aux *.blg *.fdb_latexmk *.fls *.idx *.ilg *.ind *.log *.out *.pdf *.toc
HAS_COAN = $(shell hash coan 2>&- && echo "1" || echo "0")
HAS_OUTDIR = $(shell latexmk --help | grep -- "-output-directory" | wc -l)

hotfix:
	-rm -rf $(OUTDIR)
	-mkdir $(OUTDIR)
	latexmk -pdf hackpack.tex
	-mv $(AUXFILES) $(OUTDIR)

hackpack hackpackpp:
ifeq ($(HAS_COAN), 1)
	@echo "Woah! You DO have coan installed!"
else
	@echo "WARNING: You don't have coan installed, so I'm unable to run any" \
			"preprocessing on your code. Check out the README for how to fix" \
			"this problem."
endif
ifeq ($(HAS_OUTDIR), 1)
	@echo "Woah! You have that option!"
endif

all:
	latexmk -pdf -auxdir=build -outdir=build

clean:
	-latexmk -c -outdir=build
