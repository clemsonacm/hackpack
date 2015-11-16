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
    used during ACM style programming comptetions.  If you already know your
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

#### Folder Structure and File Naming conventions
All examples assume a topic called `foo` and a sample problem `bar`:

+	All file names should be lowercase with `-` (hyphens) separating the words
	in a file.  For example, `ten-commandments.tex` instead of
	`TenCommandments.tex`
+	All sample contest problems should be in a subdirectory called `problems`
	and in a further subdirectory based on the problem name.  For example if the
	topic `foo` has a problem `bar` the path to the code sample could be `foo/problems/bar/bar.cpp`.
+	In the _rare_ circumstance that your finished product is one `tex` file,
	place it in `general` instead
+	See how the `set` material is laid out for reference.  It is in
	`structures/set`


+	`foo` the name of the branch where `foo` is being worked on
+	`foo.tex` the hackpack documentation on the algorithm
+	`foo.cpp` reference code for the foo data structure in C++ if applicable
+	`bar.in`  sample input for foo.cpp if applicable
+	`bar.out` sample output for foo.cpp if applicable
+	`bar.exe` untracked compiled binary __DO NOT ADD THIS__.  It makes it
	easier to spot in the `.gitignore`.
+	`bar.py`  a version of `foo.cpp` in python if applicable. _Alternate
	versions of algorithms in languages other than C++ should be written after
	the C++ code is written_
+	`bar.example` files such as `.vimrc` that do not have an extension normally
+	`bar.bats` Automated test case written in bats
+	`bar-test.cpp` An automated unit test written in cpp
+	`bar-test.in`  Data for the automated unit test
+	`bar-test.out` Expected output for the automated unit test

#### Writing Documentation

Please see CONTRIBUTING.md for guidelines concerning documentation.

#### Writing Code
Code Must meet the following standards:

1.  Code should be indented with tabs and not exceed 80 characters per line.
2.  Code must compile under contest conditions: `g++ -g -O2 -std=gnu++0x -static $*`
3.  Code must be delivered with the passing unit tests.
4.  Code must be commented with detailed explanations and asymptotic notation
    where applicable
5.  Code must be concise but not at the expense of readability
6.  Source code must solve a problem:  It should solve a specific problem and
    include all relevant IO and supporting code.  The algorithm should not be in
    a vacuum.
7.  The condensed hackpack version should have the following removed:

    *   Comments that are not _critical_ to the readers understanding
    *   All _library_ and `#include` code that can be found in other sections of the hackpack
    *   All input and output code that is not _critical_ to the readers
        understanding

#### Writing Tests
All code must have tests that meet the following requirements

1.	All tests should be written using the [bats framework](https://github.com/sstephenson/bats), and use `tap` compliant mode. See the `structures/set` section for an example.
2.  Test at least the upper and lower boundaries of the allowed inputs.
3.  Testing files should be postfixed by `-test` prior to the extension.  For
    example,  `foo.cpp` test files should be called `foo-test.cpp` and
    `foo-test.in` respectively
4.  Tests should be runnable by calling `make test` in the directory of the source

    +   The tests should return 0 in the case that all test cases passed
    +   The tests should return 2 in the case that any test cases failed

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

