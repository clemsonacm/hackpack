Welcome
==============================================================================

This is the Clemson ACM Repo.  We are the local chapter of the Association for
Computing Machinery at Clemson University in Clemson, South Carolina.  We do
cool computing stuff for cool computing people!

What is this repository for?
----------------------------

This repository contains resources developed to aid with doing cool stuff in
Computer Science.  The main projects are as follows:

### Clemson Hackpack and Hackpack++ 
*   the Hackpack is a concise and extensive cheatsheet/guide designed to be
    used during ACM style programming competitions.  If you already know your
    data structures and algorithms, go here.
*   The Hackpack++ is an extensive guide that includes all of the great info
    from the hackpack, but also includes a bit more detail so that you could
    use it as a learning tool for the different techniques.
*   We compile the two different versions of the hack pack from the same code
    base. Check the hack pack section for an explanation.


How do I get set up?
--------------------

Depending on what you are doing you will need different tools:

### Clemson Hackpack and Hackpack++ 

*   `git` - for tracking changes
*   `g++` - all code samples are in C++98 with C++11 listed as noted
*   `awk` - text processing tool needed for version directives
*   `pdflatex` - The Hackpack body is written in LaTeX
*   `make` - Make is to automate compilation and testing of the documents
*	`perl` - required to support renaming in version directives
*	`find` - the gnu version of find is required supporting extended posix
	regular expressions for supporting version directives.  On OSX the
	`findutils` package from homebrew can be used


Contribution Guidelines
-----------------------

### Clemson Hackpack and Hackpack++ 

For all projects and improvements:

1.  Choose an issue from the issue tracker
2.  Fork the repo to your personal account
3.  Make your changes to your personal copy
4.  When the code is complete, create a pull request in GitHub from your copy to
	ours
5.  When the pull request is reviewed and approved, the code will be merged by
    one of the owners into master.

If you have any questions related to the issues in the tracker, comment on the
issues and mention one of the owners.


#### Writing Documentation 
Documentation should be written in `LaTeX`:
For each item in the Hackpack, please include the following in clearly delineated subsections:

1.  Name and Brief Description of the topic
2.  Data structures should have a "Reference" section with a code sample of only commonly used functions
3.  A list of possible uses and applications
4.  2-3 possible contest problems; preferably of varying difficulty
5.  Sample code that answers one of the contest problems
6.  Please use the `\acmlisting` for code listings.  A caption and label should be specified.  If applicable, line ranges should be specified to limit the amount of text displayed.
7.  It would be preferred if each set of sample code had some lessons learned to point out some key elements of the implementation
8.  References using BibTeX where applicable
9.  Should be "compiled" properly by make
10.  Each sentence must be on a separate line.
11.  The condensed version of the hackpack should have the following removed:
    
    *   Introductions to the topic.
    *   Guidelines directing the reader to different sections of the hackpack.
    *   References to contest problems including statement, sample io, and
        lessons learned, but solutions should remain.
    *   As much as possible, index tags should __NOT__ be removed.


#### Different Versions of the Hack Pack

The hack pack is from one source built into two versions: one slim (`hackpack`)
and one tome-like (`hackpack++`, or as denoted in the build scripts,
`hackpackpp`). But how? By a combination of `awk` and dark magicks, authors can
use an extremely limited set of C-preprocessor-like `#ifdef`s to denote a block
of text or code as part of one version or the other. Here's an example:

	// #ifdef hackpackpp
	cout << "This is the Hack Pack: plusplus edition!" << endl;
	// #endif
	// #ifdef hackpack
	cout << "This is just the regular hack pack." << endl;
	// #endif

The first `cout` will only appear in the hackpack++'s code listing, and the
second will only appear in the normal hackpack. Note that the `#ifdefs` are
commented out: as long as the line _ends with the if directive_, they'll work
properly. You might want to comment them out so that they don't break the compilers.
Make sure you have a new line after each directive somewhere!

Here's a list of filetypes where the if directives will work:

*   `.tex`
*   `.cpp`
*   `.py`
*	`example`

#### Building the Hack Pack

The hack pack uses a Makefile for building our PDF output. Here's a rundown of
the make rules you'll probably be using:

*   `make clean` wipes out the build directory if you don't have a version of
    `latexmk` that supports the `-outdir` flag, and cleans it up with `latexmk -c`
    if you do.
*   `make hackpack` builds the slim version of the hackpack into `build/hackpack.pdf`.
*   `make hackpackpp` builds the bulky version of the hackpack into `build/hackpack.pdf`.
*   `make show` launches `evince` (a pdf viewer) to preview the hackpack.

Who do I talk to?
-----------------
Contact one of the members of the Hackpack Developers groups with any questions.

