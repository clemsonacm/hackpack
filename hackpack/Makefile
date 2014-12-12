OUTDIR      = build
PREPTYPES   = cpp|py|tex
PREPREGEX   = ".*\.\($(subst |,\|,$(PREPTYPES))\)"
AUXFILES    = *.aux *.blg *.fdb_latexmk *.fls *.idx *.ilg *.ind *.log *.out *.pdf *.toc
HAS_OUTDIR  = $(shell latexmk --help | grep -- "-output-directory" | wc -l)
PREPSCRIPT  = ./formatting/preprocessor.awk
LATEXMKOPTS = -pdf -g
BACKUPEXT   = tmpbackup
TMPEXT      = tmp

default: hackpackpp

hackpack hackpackpp:
# Back up and preprocess preprocessable files
	find . -regex $(PREPREGEX) -exec cp {} {}.$(BACKUPEXT) \; \
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

# Restore backups
	find . -regex $(PREPREGEX) -delete
	find . -iname "*.$(BACKUPEXT)" -exec rename 's/\.$(BACKUPEXT)$$//' {} \;

show:
	evince build/hackpack.pdf

clean:
	find . -iname "*.$(BACKUPEXT)" -delete
	find . -iname "*.$(TMPEXT)" -delete
ifeq ($(HAS_OUTDIR), 1)
	latexmk -c -outdir=$(OUTDIR) -auxdir=$(OUTDIR)
else
	rm -rf $(OUTDIR)
	mkdir $(OUTDIR)
endif
