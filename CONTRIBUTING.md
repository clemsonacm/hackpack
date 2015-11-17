# LaTeX Standards

## Content

### Sections on Algorithms and Data Structures

The following subsections __must__ be present before a section will be considered for inclusion:

- Description
- Reference (only for data structures)
- Applications
- Sample Problem
    - Input Format
    - Sample Input
    - Output Format
    - Sample Output
    - 'Lessons Learned'

#### Description

All data structures and algorithms should include a description section detailing:
- what it does
- the problem(s) that it solves
- how it works
- construction and run times in O-notation

#### Reference

If the section is for a data structure, it should include a subsection containing skeleton reference code.
The reference code should include only what is necessary to use the data structure and perhaps usage examples in a main function if its use is not obvious enough.

#### Applications

A list of uses for the algorithm or data structure.
For example, one application of a maximum flow algorithm is 'finding a minimum set of edges to disconnect a source and sink'.

#### Sample Problem

A problem whose solution utilizes the algorithm or data structure the section describes.
Each problem should include a description that _clearly_ describes the problem. Following the problem description should be as follows:

##### Input Format

A precise description of the input that will be supplied to the code that will solve the problem described.

##### Sample Input

An example input that fully demonstrates and conforms to the format described in 'Input Format'.
Use the `\acmlisting` command to insert your sample input.
See the 'Code Listings' 

##### Output Format

A precise description of the output that should be produced from the code that will solve the problem described.

##### Sample Output

An example input that conforms to the format described in 'Output Format'.
Use the `\acmlisting` command to insert your sample output.
See the 'Code Listings' section under 'Format' for more information.

##### Sample Solution

A solution for the problem described.
All solutions should be written in C++ __before__ providing solutions in other languages.

##### Lessons Learned

An unordered list of at least one non-trivial observation you had while writing the solution to your sample problem.

***

### Figures and Images

If adding a visual to a section would greatly aid in the understanding of the topic, doing so is highly encouraged.
Submissions should preferably be in the Encapsulated PostScript format.
This provides very clear visuals, even when scaled up or down.
Do _not_ simply pull images from the Internet.
Doing so may violate the Hack Pack licensing terms.
Any submission found to be doing so will be rejected until the appropriate changes are made.

Recommended tools:

- Ipe
- Xfig

### Indexing

Indexing entries is very helpful for finding relevant entries in the Hack Pack.
Please do not sprinkle index entries _too_ liberally throughout, as this will cause the size of the index to explode and make it harder to locate information.
If an index entry for the term you are looking to add already exists, add it anyway.
It is possible that a reader may be searching for your section.
An example of a good set of index entries can be found in the section on the Sieve of Eratosthenes.
Entries include:

- sieve
- primes
- Eratosthenes

### Citations

Information pulled from other sources needs to be properly cited.
Any information included in submissions that is not properly cited will cause the entire section to be rejected from consideration for inclusion.
References should use BibTeX where applicable.

## Format

### General Rules to Type By

- Use only one sentence per line. This makes it easier to review changes to the documentation.
- Use tabs for indentation. This allows editors to choose their preferred tab width.
- Do not use LaTeX comments. Anything important enough to put in a comment should be put into the text. This excludes primarily technical parts like `style.tex`.

### Indentation

Please use one tab per indent.
Any text wrapped in the `\begin{}` and `\end{}` commands should be indented; this includes lists (both itemize and description).

### Sectioning

All sections should have headers using the appropriate LaTeX sectioning commands:

| Section | Command |
|---------|:-------:|
| section title | `\section{}` |
| Applications | `\subsection{}` |
| Sample Problem | `\subsection{}` |
| Input Format | `\subsubsection{}` |
| Sample Input | `\subsubsection{}` |
| Output Format | `\subsubsection{}` |
| Sample Output | `\subsubsection{}` |
| Lessons Learned | `\subsubsection{}` |

### Code Listings

Always use the `\acmlisting` command when including code, input, or output in the Hack Pack.
The label and caption should always be set as well; both should be set to the same value.
A code listing for a sample problem titled 'Cows Amok' would be inserted like so:

`\acmlisting[label=Cows Amok, caption=Cows Amok]{./path/to/cows-amok.cpp}`

Sample input for the problem would be inserted like so:

`\acmlisting[label=Cows Amok Sample Input, caption=Cows Amok Sample Input]{./path/to/cows-amok.in}`

Sample output for the problem would be inserted like so:

`\acmlisting[label=Cows Amok Sample Output, caption=Cows Amok Sample Output]{./path/to/cows-amok.out}`

### Style Changes

Any changes to the style of the document must be cleared with the core Hack Pack team before implementing.
Any submissions that change the style of document (even if not global) without prior approval will be rejected.

## Condensing

Each submission to the Hack Pack must also have a condensed version for inclusion in the condensed Hack Pack as well.
This is trivial.

### Content

A complete, condensed section of the Hack Pack should include:

- a brief description of the problem (possibly gleaned from the full description)
- a list of applications
- reference code (if the section is for a data structure)
- sample solutions for each included problem

### How To Condense Your Section

We have defined special keywords (from a familiar language) to separate information that should be displayed in each section: `#ifdef hackpack`, `#ifdef hackpackpp`, and `#endif`.
Wrap a section with the `#ifdef hackpack` and `#endif` to include the section only in the condensed version of the Hack Pack.
Wrap a section with the `#ifdef hackpack` and `#endif` to include the section only in the full version of the Hack Pack.
Any section that is not wrapped with either set of keywords will be included in both versions of the Hack Pack.

## Submission

Before submitting a section for inclusion in the Hack Pack, ensure that both the Hack Pack and Hack Pack++ build (using only `make`) on the McAdams lab machines _without stopping_.

## Still Not Sure?

We strive to make our content as clear and concise as possible, but it is always possible that we have left some content off.
If you have any question about any part of your LaTeX, it is always a good idea to consult entries that have already made it into the Hack Pack.
In particular, the section on sets is an example of an excellent addition to the Hack Pack.
Failing that, feel free to email any of the Hack Pack development team, `@clemsonacm/hackpack-developers`.
