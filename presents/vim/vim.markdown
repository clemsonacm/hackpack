Introduction to Vim
====================

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

Robert Underwood - ACM Vice-President\
 Austin Anderson - ACM President


Coming Up
=========
1.  Setting Expectations
2.  What is Vim?

Setting some Expectations
==========================
+   This discussion will _not_:
    +   Cover what `vimtutor` will teach you
    +   Make you magically a Vim guru
    +   Show even 10% of the power of Vim

+   This discussion _will_:
    +   Show you some of the coolest features of Vim
    +   Teach you enough to teach yourself

--TODO it is a quote from the Vim guru I learned from this summer
>   Most people use only 10% of the functionality of Vim
>   The 10% only differs from person to person

What is Vim?
============
--TODO is this less redundant?
Vim is...
---------
+   A programmer's text editor
+   A tool that is meant to be learned

Vim is NOT
----------
+   All of the tools in you tool box

Composability
=============
--TODO helps to have the right title;  I think that this is an important basic
--TODO concept that makes understanding the rest of the editor easier
+   To take elements to make up a whole
+   Actions and Motions
    +   Actions do something
    +   Motions move the cursor
+   most commands are composed of Action and Motion 

Common Motions
===================
+	blocks `w`, `s`, `p`, `b`, `B`, 
+	`|` column
+	`gj`, `gk` wraped up/down
+	`(` and `)` sentensces
+	`[` and `]` paragraphs
+	`:h motion.txt`

Antipatterns
============
--TODO maybe include some numbers on just how important it is to be efficient?
--TODO I don't have any specific numbers, just a concept I wanted to introduce
+   A bad way of doing something that becomes habit
    +   `ddO` instead of `S`

Fixing Some Common Annoyances
=============================
+   Use .vimrc to store preferences 
+   Turn on the mouse `set mouse=a`
+   Turn on syntax highlighting `syntax on`
+   Set your background color `set bg=dark`
+   I hate escape --TODO I put this here as for a general introduction to key bindings

Copy and Paste
==============
--TODO this slide doesn't seem to offer very practical examples
--TODO there's also quite a lot of content on registers, which I actually don't use all that much.
--TODO it is actually one of the features that I tend to use and is a building
--TODO block for building complex macros, and it is different than what other editors
--TODO use so it is worth spending some time on.  Plus, I planned to breeze
--TODO through these slides and put them here more as a here is whats possible instead
--TODO of a here is how to do every thing.
+   Forget Copy and Paste
+   Think registers
    +   You now have 20 copy buffers
+   `"+` register 
+   `:reg` - view the contents of registers
+   `<C-r>` in insert mode puts the register

Common registers
===================
+   `"[1-9]` history registers
+   `"0` the yank register
+   `"[a-z]` named registers
+   `"[A-Z]` same as "[a-z] but append

Important registers
=========================
+   `"/` current search pattern
+   `"-` small delete
+   `"=` expression register  
+   `"_` the blackhole register

Read-only registers
===================
+   `":` last `:` command 
+   `".` last inserted text 
+   `"%` filename of the current buffer.
+   `"#` filename of the alternate file
    +   More on that in a minute

Macros
======

+	`.` short macro operator
+	`qa` record a macro in register `a`
+	`q` end recording a macro
+	`@a` execute the macro in register `a`

Multiple Files
==============
+   Use buffers, windows, and tabs 
+   `:argdo`, `:bufdo`, `:tabdo`

Windows
=======

+	very handy for viewing multiple files at once
+   `<C-w>` prefixes most "window" commands
+	`:vsp` vertical split
+	`:sp` horizontal split
+	`[vert] res` resize windows


Buffers
=======

+	`:ls`
+	`set hidden` 
+   `:bn`, `:bd`, `:bp`
+   `:b<num>` change to buffer number
+	`:b <name>` fuzzy match buffer change

Tabs
====

+	Useful for holding different sets of windows
+	`gt` go to the next tab
+	`gT` go to the previous tab
+	`:tabnew` create a new tab

Syntax Completion
==============================
+   Syntax Completion
    +   `<C-n>` - Next default completion
    +   `<C-p>` - Previous default completion
+   Omni-completion `<C-x><C-o>` 
    +   C (limited C++)
    +   CSS, HTML, XHTML, JS
    +   PHP, RUBY

Programming Completion
======================
+   `<C-x><C-f>` File paths
+   `<C-x><C-d>` Definition
+   `<C-x><C-]>` Tags
+   `<C-x><C-i>` Keywords
+   `<C-x><C-l>` lines

Other Completions
=================
+   `<C-x><C-t>` Thesaurus
+   `<C-x><C-k>` Dictionary
+   `<C-x><C-s>` Spelling
+   `<C-x><C-v>` Vim commands 

Templates
==============================
--TODO I moved this up to allow for a cleaner segue
+   `0r ~/path/to/template`
+   Reads in a template to new files
+   Can be blocked on file type using autocmds

Snippets
==============================
+   Abbreviations will do simple snippets
+   `:ab` create/view abbreviations
+   Snipmate and Ultisnips
    --TODO could use this to segue into plugins
	--TODO I agree I'll put it here
    +   Better snippets support
    +   Provide advanced completion features

Plugins and Plugin Managers
===========================
+	Vim is extensible via plugins
+	Can be written in `vimscript` and other languages
+	stored in `~/.vim`
+   `vundle` great plugin manager
+	Often prefixed by `<LEADER>`

Some Useful Plugins
===================
+	`scrooloose/NERDTree` better file manager
+	`scrooloose/syntastic` check syntax while typing
+	`tpope/vim-fugitive` git interaction
+	`tpope/vim-surround` More motions
+	`SirVer/ultisnips` Better snippets
+	`honza/vim-snippets` Some useful standard snippets

Navigating large code bases
==========================
+   Ctags
    +   `<C-]>` go to tag under cursor
    +   `<C-T>` go back to last place
    +   `:tags` show the tag stack
+   Cscope
    +   More powerful but confined to C/C++
    +   Much more intelligent 
    +   Can be configured otherwise, but its hacky

Using Vim to Test faster
========================
+   `:make <make_target>`
+   `:set makeprg`
+   `:cn` `:cw` `:cp` `]c` `[c`
+   `:copen`
+   `:shell`


Further Resources
=================
--TODO include hyperlinks
+   Practical Vim by Drew Neil
+   Vimcasts by Drew Neil
+   Vimtips wiki
+   `:help` -- an incredible resource!

Questions
=========

Send us feedback at `acm@cs.clemson.edu`!

