# Coding Standards

## General Guidelines

We largely follow the style guidelines found in the [Linux Kernel Coding
Style][Linux].  There are a few sections that do not specific apply to the
Hack Pack namely and can be ignored : 10 (Kconfigs), 13(Kernel Messages),
14(Memory Allocations in the Kernel), 17(Kernel Macros), and 19 (Inline
Assembly).

Additionally, we have a few additional guidelines:


1.  Code must compile under contest conditions: `g++ -g -O2 -std=gnu++0x -static $*`
2.  Code must be delivered with the passing unit tests.
3.  Code must be commented with detailed explanations and asymptotic notation
    where applicable
4.  Source code must solve a problem:  It should solve a specific problem and
    include all relevant IO and supporting code.  The algorithm should not be in
    a vacuum.
5.  The condensed hackpack version should have the following removed:

    -   Comments that are not _critical_ to the readers understanding
    -   All _library_ and `#include` code that can be found in other sections of the hackpack
    -   All input and output code that is not _critical_ to the readers
        understanding

## Writing Tests
All code must have tests that meet the following requirements

1.	All tests should be written using the [bats framework][bats], and use `tap`
	compliant mode. See the `structures/set` section for an example.
2.  Test at least the upper and lower boundaries of the allowed inputs.
3.  Testing files should be postfixed by `-test` prior to the extension.  For
    example,  `foo.cpp` test files should be called `foo-test.cpp` and
    `foo-test.in` respectively
4.  Tests should be runnable by calling `make test` in the directory of the source

    +   The tests should return 0 in the case that all test cases passed
    +   The tests should return 2 in the case that any test cases failed

## Folder Structure and File Naming conventions
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
+	In the case of multiple files of the same type, they should be postfixed a
	number for example `bar-test1.out` or `bar-test1.in`.

[Linux]: https://www.kernel.org/doc/Documentation/CodingStyle
[bats]: https://github.com/sstephenson/bats
