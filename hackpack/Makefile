OUTDIR = build
AUXFILES = *.aux *.blg *.fdb_latexmk *.fls *.idx *.ilg *.ind *.log *.out *.pdf *.toc
HAS_COAN = $(shell hash coan 2>&- && echo "1" || echo "0")
HAS_OUTDIR = $(shell latexmk --help | grep -- "-output-directory" | wc -l)

hotfix:
	-rm -rf $(OUTDIR)
	-mkdir $(OUTDIR)
	-latexmk -pdf
	-mv $(AUXFILES) $(OUTDIR)

hackpack hackpackpp:
# Back up all preprocessable files


# Preprocess preprocessable files
ifeq ($(HAS_COAN), 1)
	@echo "INFO: You have coan installed! Preprocessing solution code snippets..."
else
	@echo "INFO: You don't have 'coan' installed, so I'm unable to run any" \
			"advanced preprocessing on your solution code."
	@echo "INFO: Instead, any code that's printed in your build of the hack" \
			"will simply have '#if[n]def hackpack[pp]' and '#endif' lines removed."
	@echo "INFO: Check out the README for how to fix this problem."
endif

# Build the PDF and auxiliary files into the OUTDIR
ifeq ($(HAS_OUTDIR), 1)
	@echo "Woah! You have that option!"
else
	@echo "You don't have that option."
endif

# Undo all that preprocessing
ifeq ($(HAS_COAN), 1)
	@echo "Woah! You DO have coan installed!"
endif

all:
	latexmk -pdf -auxdir=build -outdir=build

clean:
	-latexmk -c -outdir=build
