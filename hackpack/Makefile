# Where to put auxiliary files and the hack pack PDF.
OUTDIR = build

# Filetypes that the preprocessor script runs over. Separated with pipes, e.g. a|b
PREPTYPES = cpp|py|tex

# `find` regex to match the preprocessable files. Substitutes to escape pipes.
PREPREGEX = ".*\.\($(subst |,\|,$(PREPTYPES))\)"

# Auxiliary files to move to the OUTDIR.
AUXFILES = *.aux *.blg *.fdb_latexmk *.fls *.idx *.ilg *.ind *.log *.out *.pdf *.toc

# 1 if your version of `latexmk` supports the `-outdir` option, 0 otherwise.
HAS_OUTDIR = $(shell latexmk --help | grep -- "-output-directory" | wc -l)

# Location of the preprocessing script.
PREPSCRIPT = ./formatting/preprocessor.awk

# -pdf to generate a pdf, -g to force recompilation.
LATEXMKOPTS = -pdf -g

# Extension for backups of preprocessable files.
BACKUPEXT = tmpbackup

# Extension for temporary location for preprocessed files.
TMPEXT = tmp

# Build the Hackpack++ by default.
default: hackpackpp

# Use `make hackpack` or `make hackpackpp` to build the hackpack or hackpack++.
hackpack hackpackpp:
	# Back up and preprocess preprocessable files.
	find . -regex $(PREPREGEX) -exec cp {} {}.$(BACKUPEXT) \; \
	-exec sh -c 'awk -v V=$@ -f $(PREPSCRIPT) {} > {}.$(TMPEXT)' \; \
	-exec mv {}.$(TMPEXT) {} \;

	# Build the PDF and auxiliary files into the OUTDIR.
ifeq ($(HAS_OUTDIR), 1)
	-latexmk $(LATEXMKOPTS) -auxdir=$(OUTDIR) -outdir=$(OUTDIR)
else
	-rm -rf $(OUTDIR)
	-mkdir $(OUTDIR)
	-latexmk $(LATEXMKOPTS)
	-mv $(AUXFILES) $(OUTDIR)
endif

	# Delete preprocessed files.
	-find . -regex $(PREPREGEX) -delete
	# Restore backups of preprocessed files.
	-find . -iname "*.$(BACKUPEXT)" -exec rename 's/\.$(BACKUPEXT)$$//' {} \;

.PHONY: clean show test
# Display the hack pack, if it exists.
show:
	evince $(OUTDIR)/hackpack.pdf

# Delete temporary files that might exist and clean the OUTDIR.
clean:
	-find . -iname "*.$(BACKUPEXT)" -delete
	-find . -iname "*.$(TMPEXT)" -delete
	-./modules.sh clean
ifeq ($(HAS_OUTDIR), 1)
	-latexmk -c -outdir=$(OUTDIR) -auxdir=$(OUTDIR)
else
	-rm -rf $(OUTDIR)
	-mkdir $(OUTDIR)
endif

test:
	./modules.sh test
