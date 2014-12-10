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

HAS_COAN := $(shell hash hatnsoehu 2>&- && echo "1" || echo "0")
HAS_OUTDIR := $(shell latexmk --help | grep -- "-output-directory" | wc -l)

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
