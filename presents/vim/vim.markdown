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
    +   Magically make you a Vim guru
    +   Show even 10% of the power of Vim

+   This discussion _will_:
    +   Show you some of the coolest features of Vim
    +   Teach you enough to teach yourself

>   Most people use only 10% of the functionality of Vim.
>   The 10% only differs from person to person

What is Vim?
============

Vim is...
---------
+   A programmer's text editor
+   An extremely valuable tool to master

Vim is NOT
----------
+   A replacement for **all** of the tools in your tool box

Composability
=============
+   Most commands are composed of an action and a motion
    +   Actions do something
    +   Motions move the cursor
+   Most editors don't have anything like this!

Uncommon Motions
================
+	Last point in the change list: `g;` (`g,` to go back)
+	Text objects: `w`, `s`, `p`, `b`, `B`, etc.
    + Pneumonic? 
        + "a word" -> `aw`
        + "inner block" -> `ib`
+ Next character: 
    + `f<char>` (inclusive)
    + `t<char>` (exclusive)
+	`{number}|`: to a certain column
+	`gj`, `gk` move up and down over window-wrapped lines
+	`(` and `)`: sentences
+	`[` and `]`: paragraphs
+	More: see `:h motion.txt`

Antipatterns
============
+   A less efficient way of doing something that becomes a bad habit
    +   `ddO` instead of `S`
	+	`dbx` instead of `daw`
	+	`f<lvt>U` instead of `gUit`
+ Be careful not to worry about optimization more than working, though

Fixing Some Common Annoyances
=============================
+   Use .vimrc to store preferences
+   Turn on the mouse: `set mouse=a`
+   Turn on syntax highlighting: `syntax on`
+   Set your background color: `set bg=dark`

Copy and Paste
==============
+   Forget Copy and Paste
+   Think registers
    +   You now have 35 copy buffers
+   `"+` is the X server (i.e. system) copy/paste register, copy to here to
    copy out of Vim
+   `:reg` - view the contents of registers
+   `<C-r>` in insert mode puts the register

Common registers
===================
+   `"[1-9]` history registers
+   `"0` the yank register
+   `"[a-z]` are named registers
+   `"[A-Z]` same as "[a-z] but append

Important registers
=========================
+   `"/` current search pattern
+   `"-` small delete
+   `"=` expression register  
+   `"_` the black hole register

Read-only registers
===================
+   `":` last `:` command 
+   `".` last inserted text 
+   `"%` filename of the current buffer.
+   `"#` filename of the alternate file
    +   More on that in a minute
+   `:h registers`

Macros
======

+	`.`: the short macro operator
    + `.` repeats the last change
+	`qa` record a macro in register `a`
+	`q` to finish recording
+	`@a` execute the macro in register `a`
+ Macros are saved as text, so you can edit them manually!

Multiple Files
==============
+ From `:h windows`:
   + A buffer is the in-memory text of a file.
   + A window is a viewport on a buffer.
   + A tab page is a collection of windows.
+   Use buffers, windows, and tabs 
+   `:argdo`, `:bufdo`, `:tabdo`

Buffers
=======

+ Just a window into a file on disk.
+ Vim remembers a lot of them.
+	`:ls` - check out the buffer list
+	`set hidden` - don't unload buffers when they're not being looked at.
  + `:bn` - Next buffer in the list.
  + `:bp` - Previous buffer in the list.
  + `:bd` - Unload and delete the buffer from the buffer list
  + `<C-^>` - Toggle between this and the "alternate" file (usually the last edited)
+   `:b<num>` change to buffer number <num>
+	`:b <name>` fuzzy match buffer change (use tab complete!)


Windows
=======

+	Very handy for viewing multiple files at once
+   `<C-w>` prefixes most window commands
+	`<C-w>v` vertical split
+	`<C-w>s` horizontal split
+	`<C-w>n` new buffer in a horizontal split window
+	`<C-w>c` close the window -- useful for escaping from `:h <anything>`.
+	Tons of window commands! Check `:h windows`

Tabs
====

+	Not quite the tabs you're used to in, say, Gedit
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

Digraphs & Special Characters
=============================
+ Digraphs: insert weird characters like ë, Ω, etc.
  + In insert mode: `<c-k>`, followed by one or two characters
  + Example: `i<c-k>a:` yields ä.
  + Check `:h digraphs` for a list of them all!
+ `<c-v>` in insert mode: insert the next character literally
  + Tab key doesn't insert a tab character? `<c-v><tab>`

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
+	Can be written in `vimscript`, a.k.a. VimL, and other languages
+	Stored in `~/.vim`
+   [`vundle`](https://github.com/gmarik/Vundle.vim) is a plugin that can
    manage your plugins
+	Commands often prefixed by `<LEADER>` to avoid overwriting other commands
  +	You'll sometimes need to set them up yourself in `.vimrc`
  +	The `<LEADER>` key is `\\` by default, some people like space or comma

Some Useful Plugins
===================
+	`scrooloose/NERDTree` - Tree-style file listing sidebar
+	`scrooloose/syntastic` - Check syntax while typing
+	`tpope/vim-fugitive` - Git interaction
+	`tpope/vim-surround` - Edit surroundings (like quickly quoting things)
+	`SirVer/ultisnips` - Better snippet system
+	`honza/vim-snippets` - Some useful standard snippets
+	Anything by Tim Pope (`tpope`) is going to be useful.

Navigating large code bases
==========================
+   Ctags
    +   `<C-]>` go to tag under cursor
    +   `<C-T>` go back to last place
    +   `:tags` show the tag stack
+   Cscope
    +   More powerful but confined to C/C++
    +   Much more intelligent 
    +   Can be configured otherwise, but it's hacky

Using Vim to Test faster
========================
+   `:make <make_target>`
+   `:set makeprg`
+   `:cn` `:cw` `:cp` `]c` `[c`
+   `:copen`
+   `:shell`

Other Cool Commands
===================
+   `gq<motion>`: hard word wrap a line, paragraph, etc.
+   `v` and `V`: visual and linewise visual modes.
    +   Check `:h visual-mode`: super useful!
+   `:`: command line - substitute text, run commands, and more! `:h :`

Further Resources
=================
+   [Practical Vim by Drew Neil](https://pragprog.com/book/dnvim/practical-vim)
+   [Vimcasts by Drew Neil](http://vimcasts.org/)
+   [Vimtips wiki](http://vim.wikia.com/wiki/Vim_Tips_Wiki)
- [Vundle](https://github.com/gmarik/Vundle.vim) 
+	[Vim Awesome](http://vimawesome.com/) - tons of plugins!
+   `:help` -- an incredible resource!

Questions?
==========

Send us feedback at `acm@cs.clemson.edu`!

