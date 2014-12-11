OUTDIR      = build
PREPTYPES   = cpp|py
AUXFILES    = *.aux *.blg *.fdb_latexmk *.fls *.idx *.ilg *.ind *.log *.out *.pdf *.toc
HAS_OUTDIR  = $(shell latexmk --help | grep -- "-output-directory" | wc -l)
PREPSCRIPT  = ./formatting/preprocessor.awk
LATEXMKOPTS = -pdf -g
BACKUPEXT   = tmpbackup
TMPEXT      = tmp

default: hackpackpp

hackpack hackpackpp:
	find . -regex ".*\.\($(subst |,\|,$(PREPTYPES))\)" -exec cp {} {}.$(BACKUPEXT) \; \
	-exec sh -c 'awk -v V=$@ -f $(PREPSCRIPT) {} > {}.$(TMPEXT)' \; \
	-exec mv {}.$(TMPEXT) {} \;

# Build the PDF and auxiliary files into the OUTDIR
ifeq ($(HAS_OUTDIR), 1)
	latexmk $(LATEXMKOPTS) -auxdir=$(OUTDIR) -outdir=$(OUTDIR)
else
	-rm -rf $(OUTDIR)
	-mkdir $(OUTDIR)
	latexmk $(LATEXMKOPTS)
	-mv $(AUXFILES) $(OUTDIR)
endif

	find . -regex ".*\.\($(subst |,\|,$(PREPTYPES))\)" -delete
	find . -iname "*.$(BACKUPEXT)" -exec rename 's/\.$(BACKUPEXT)$$//' {} \;

show:
	evince build/hackpack.pdf

all:
	latexmk -pdf -auxdir=build -outdir=build

clean:
	find . -iname "*.$(BACKUPEXT)" -delete
	find . -iname "*.$(TMPEXT)" -delete
	-latexmk -c -outdir=build
