Intermediate Vim
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

>   Most people use only 10% of the functionality of Vim
>   The 10% only differs from person to person

What is Vim?
============

Vim is...
---------
+   A programmer's text editor
+   A tool that is meant to be learned

Vim is NOT
----------
+   All of the tools in your tool box

Composability
=============
+   To take elements to make up a whole
+   Actions and Motions
    +   Actions do something
    +   Motions move the cursor
+   Most commands are composed of Action and Motion 

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
+   A bad way of doing something that becomes habit
    +   `ddO` instead of `S`
	+	`dbx` instead of `daw`
	+	`f<lvt>U` instead of `gUit`

Fixing Some Common Annoyances
=============================
+   Use .vimrc to store preferences 
+   Turn on the mouse `set mouse=a`
+   Turn on syntax highlighting `syntax on`
+   Set your background color `set bg=dark`

Copy and Paste
==============
+   Forget Copy and Paste
+   Think registers
    +   You now have 35 copy buffers
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
+	`:vsp`, `<C-w><C-v>` vertical split
+	`:sp`, <C-w><c-s>` horizontal split
+	`[vert] res` resize windows


Buffers
=======

+	`:ls`
+	`set hidden` 
+   `:bn`, `:bd`, `:bp`, `<C-^>`
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
+   Syntax Completion in insert mode
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

Digraphs
========
+	`<C-v>` in insert mode
+	see `:h digraph` 

Templates
==============================
+   `0r ~/path/to/template`
+   Reads in a template to new files
+   Can be blocked on file type using autocmds

Snippets
==============================
+   Abbreviations will do simple snippets
+   `:ab` create/view abbreviations
+   Snipmate and Ultisnips
    +   Better snippets support
    +   Provide advanced completion features

Plugins and Plugin Managers
===========================
+	Vim is extensible via plugins
+	Can be written in `vimscript` and other languages
+	Stored in `~/.vim`
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
+   [Practical Vim by Drew Neil](https://pragprog.com/book/dnvim/practical-vim)
+   [Vimcasts by Drew Neil](http://vimcasts.org/)
+   [Vimtips wiki](http://vim.wikia.com/wiki/Vim_Tips_Wiki)
+	[Vim Awesome](http://vimawesome.com/)
+   `:help` -- an incredible resource!

Questions
=========

Send us feedback at `acm@cs.clemson.edu`!

