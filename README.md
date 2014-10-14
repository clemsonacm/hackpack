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
    data structures and algorithms go here.
*   The Hackpack++ is a extensive guide that includes all of the great info
    from the hackpack, but also includes a bit more detail so that you could
    use it as a learning tool for the different techniques.

###   Presentations 
In addition to the Hackpack, we put on a series of educational seminars
throughout the year.  They cover neat topics and tools in CS. We currently
have presentations for the following:

*   Linux is Scary - a basic introduction to linux for new folks
*   Git Thee to a Version Control System - A introduction to version control and
    git
*   Vim - An advanced seminar on how to get more out of vim


How do I get set up?
--------------------

Depending on what you are doing you will need different tools:

### Clemson Hackpack and Hackpack++ 

*   `git` - for tracking changes
*   `g++` - all code samples are in C++98 with C++11 listed as noted
*   `pdflatex` - The Hackpack body is written in LaTeX
*   `make` - Make is to automate compilation and testing of the documents

### Presentations 

*   `git` - for tracking changes
*   `pandoc` - convert markdown files to reveal.js
*   `Firefox` or `Chrome` - any modern web browser really. See reveal.js for more
    documentation

Contribution Guidelines
-----------------------

### Clemson Hackpack and Hackpack++ 

For all projects and improvements:

1.  Clone the repo
2.  Choose an issue from the issue tracker
3.  Checkout a new branch with the topic as the name
4.  Push the branch to the repo
5.  When the branch is complete, create a pull request in Bitbucket
6.  When the pull request is reviewed and approved, the code will be merged by
    one of the admins into master.

If you have any questions related to the issues in the tracker, comment on the
issues and CC one of the admins.

#### Folder Structure and File Naming conventions
All examples assume a topic called `foo` and a sample problem `bar`:

+	All file names should be lowercase with `-` (hyphens) separating the words
	in a file.  For example, `ten-commandments.tex` instead of
	`TenCommandments.tex`
+	All sample contest problems should be in a subdirectory called `problems`
	and futher in a subdirectory based on the problem name.  For example if the
	topic `foo` has a problem `bar` the path to the code sample could be `foo/bar.cpp`
+	In the _rare_ circumstance that your finished product is one `tex` file and
	place it in general instead
+	See how the `set` material is laid out for reference.  It is in
	`structures/set`


+	`foo` the name of the branch were `foo` is being worked on
+	`foo.tex` the hackpack documentation on the algorithm
+	`foo.cpp` reference code for the foo data structure in C++ if applicable
+	`bar.in`  sample input for foo.cpp if applicable
+	`bar.out` sample output for foo.cpp if applicable
+	`bar.exe` untracked compiled binary __DO NOT ADD THIS__  it to make it
	easier to spot in the `.gitignore`
+	`bar.py`  a version of `foo.cpp` in python if applicable. _alternate
	versions of algorithms in languages other than C++ should be written after
	the C++ code is written_
+	`bar.example` files such as `.vimrc` that do not have an extension normally
+	`bar-test.cpp` An automated unit test written in cpp
+	`bar-test.in`  Data for the automated unit test
+	`bar-test.out` Expected output for the automated unit test





#### Writing Documentation 
For each item in the Hackpack, please include the following in clearly delineated subsections:

1.  Name and Brief Description of the topic
2.  Data structures should have a "Reference" section with a code sample of only commonly used functions
3.  A list of possible uses and applications
4.  2-3 possible contest problems; preferably of varying difficulty
5.  Sample code that answers one of the contest problems
6.  References using BibTeX where applicable
7.  Should be "compiled" properly by pdflatex and the make
8.  Each sentence must be on a separate line.

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

#### Writing Tests
All code must have tests that meet the following requirements

1.  Test at least the upper and lower boundaries of the allowed inputs.  
2.  Testing files should be postfixed by `-test` prior to the extension.  For
	example,  `foo.cpp` test files should be called `foo-test.cpp` and
	`foo-test.in` respectively
3.  Tests should be runnable by calling `make test` in the directory of the source

### Presentations

If you have a good presentation let us know.  We will use reveal.js and markdown
for presentations.  If you have an improvement, follow the procedure above.

Who do I talk to?
-----------------
Contact <acm@cs.clemson.edu> with any questions
