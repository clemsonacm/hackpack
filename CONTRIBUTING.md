# Coding Standards

## Quick Start

When coding for the hackpack, we use the following style:

-   Use tabs for indentation
-   Try to keep lines to 80 characters
-   Use K&R style braces
-   names should be descriptive, but not _extreemly_ long
-   use `snake_case` for everything except constants and filenames
-   use `UPPER_CASE` for constants
-   use `example-name.txt` for file names

Further more in order for code to be accepted it must:

-   Be delivered with passing unit tests written in [bats][bats]
-   Compile with `g++ -g -O2 -sstd=gnu++0x -static`

In short, C++ should look like this:

```c++
#include<iostream>
using namespace std;

#define CONSTANT_VALUE 7
typedef pair<int,int> pii;

int example_global;

int main()
{
int size;
cin >> size;

int i = 0;
while (i < size) {
	cin >> values[i];
	i++;
}

pii tmp = min_max(values,size);

cout << tmp.first << ", " << tmp.second << endl;

}

pii min_max(const int * values, unsigned int size)
{
// Computes the min and max of an array in O(N) time
// Parameters:
//     values - the array to search
//     size - size of the array
// Returns: the make_pair(min,max)

int min_value = values[0];
int max_value = values[0];

for (int i = 0; i < size; i++) {
	if (values[i] < min_value)
		min_value = values[i];
	if (values[i] > max_value)
		max_value = values[i];
}

return make_pair(min_value, max_value);
}
```


## Detailed Guidelines

### Code

We largely follow the style guidelines found in the [Linux Kernel Coding
Style][Linux].  There are a few sections that do not specifically apply to the
Hack Pack and can be ignored : 

-	10 - Kconfigs
-	13 - Kernel Messages
-   14 - Memory Allocations in the Kernel
-   17 - Kernel Macros
-   19 - Inline Assembly

Additionally, we have a few additional guidelines:


1.  Code must compile under contest conditions: `g++ -g -O2 -std=gnu++0x -static $*`
2.  Code must be delivered with the passing unit tests.
3.  Code must be commented with detailed explanations and asymptotic notation
    where applicable
4.  Source code must solve a problem:  It should solve a specific problem and
    include all relevant IO and supporting code.  The algorithm should not be in
    a vacuum.
5.  The condensed Hack Pack version should have the following removed:

    -   Comments that are not _critical_ to the readers understanding
    -   All _library_ and `#include` code that can be found in other sections of the Hack Pack
    -   All input and output code that is not _critical_ to the readers
        understanding

### Writing Tests

All code must have tests that meet the following requirements:

1.	All tests should be written using the [bats framework][bats], and use `tap`
	compliant mode. See the `structures/set` section for an example.
2.  Test at least the upper and lower boundaries of the allowed inputs.
3.  Testing files should be postfixed by `-test` prior to the extension.  For
    example,  `foo.cpp` test files should be called `foo-test.cpp` and
    `foo-test.in` respectively
4.  Tests should be runnable by calling `make test` in the directory of the source

    +   The tests should return 0 in the case that all test cases passed
    +   The tests should return 2 in the case that any test cases failed

### Folder Structure and File Naming conventions

All examples assume a topic called `foo` and a sample problem `bar`:

+	All file names should be lowercase with `-` (hyphens) separating the words
	in a file.  For example, `ten-commandments.tex` instead of `TenCommandments.tex`
+	All sample contest problems should be in a subdirectory called `problems`
	and in a further subdirectory based on the problem name.  For example if the
	topic `foo` has a problem `bar` the path to the code sample could be `foo/problems/bar/bar.cpp`.
+	In the _rare_ circumstance that your finished product is one `tex` file,
	place it in `general` instead
+	See how the `set` material is laid out for reference.  It is in
	`structures/set`

#### Detailed Example

+	`foo` The name of the branch where `foo` is being worked on
+	`foo.tex` The Hack Pack documentation on the algorithm
+	`foo.cpp` Reference code for the foo data structure in C++ if applicable
+	`bar.in`  Sample input for foo.cpp if applicable
+	`bar.out` Sample output for foo.cpp if applicable
+	`bar.exe` Untracked compiled binary __DO NOT ADD THIS__.  It makes it
	easier to spot in the `.gitignore`.
+	`bar.py`  A version of `foo.cpp` in python if applicable. _Alternate
	versions of algorithms in languages other than C++ should be written after
	the C++ code is written_
+	`bar.example` Files such as `.vimrc` that do not have an extension normally
+	`bar.bats` Automated test case written in bats
+	`bar-test.cpp` An automated unit test written in cpp
+	`bar-test.in`  Data for the automated unit test
+	`bar-test.out` Expected output for the automated unit test
+	In the case of multiple files of the same type, they should be postfixed by a
	number for example `bar-test1.out` or `bar-test1.in`.

[Linux]: https://www.kernel.org/doc/Documentation/CodingStyle
[bats]: https://github.com/sstephenson/bats
