Introduction to Vim
====================

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

Robert Underwood - CS Major\
 Austin Anderson - ACM President


Coming Up
=========
1.  Setting Expectations
2.  What is Vim?

Setting some Expectations
==========================
+   This discussion will not:
    +   Go over the basics in vimtutor
    +   Make you magically a Vim guru
    +   Show even 10% of Vim's power

+   This discussion will:
    +   Show you some of the cool and useful features
    +   Teach you enough to teach yourself

>   Most people use only 10% of the functionality of vim
>   The 10% only differs from person to person

What is Vim?
============

Vim is
------
+   a programmers text editor
+   Very programmable and extensible
+   A tool that is meant to be learned
+   Awesome

Vim is NOT
----------
+   All of the tools in you tool box
+   A Word Processor

Composability
=============
+   To take elements to make up a whole
+   Actions and Motions
    +   Motions move the cursor
    +   Actions do something
+   combinations of Action and Motion 

Antipaterns
============
+   A bad way of doing something that becomes habit
    +   llllllll instead of e
    +   ddi instead of C

Fixing Some Common Annoyances
=============================
+   Use .vimrc to store preferences
+   Turn on the mouse
+   Turn on Syntax Highlighting
+   Set your background color
+   I hate escape
+   Each annoyance has a reason

Copy and Paste
==============
+   Forget Copy and Paste
+   Think registers
    +   You now have 20 copy buffers
+   `"+` register 
+   `:reg` - view the contents of registers
+   `^r` in insert mode puts the register

Common registers
===================
+   `"[1-9]` history buffers
+   `"0` the yank buffer
+   `"[a-z]` named registers
+   `"[A-Z]` same as "[a-z] but append

Important registers
=========================
+   `"+` The "global" register
+   `"/` current search pattern
+   `"-` small delete
+   `"=` expression register  
+   `"_` the blackhole register

Read-only registers
===================
+   `":` last Ex command
+   `".` last inserted text
+   `"%` filename of the current buffer.  
+   `"#` filename of the alternate file 
    +   More on that in a minute


Multiple Files
==============
+   Use buffers and windows
+   `^w` is prefixes most "window" commands
+   very handy for viewing multiple files
+   :vsp, :sp, :res :bn :bd :bp
+   :b will change the buffer

Syntax Completion
==============================
+   Syntax Completion
    +   `^n` - Next default completion
    +   `^p` - Previous default completion
+   Omni-completion `^x^o`
    +   C (limited C++)
    +   CSS, HTML, XHTML, JS
    +   PHP, RUBY

Programming Completion
======================
+   `^x^f` File paths
+   `^x^d` Definition
+   `^x^]` Tags
+   `^x^i` Keywords
+   `^x^l` lines

Other Completions
=================
+   `^x^t` Thesaurus
+   `^x^k` Dictionary
+   `^x^s` Spelling
+   `^x^v` Vim commands 

Snippets
==============================
+   Abbreviations will do simple snippets
+   `:ab` create/view abbreviations
+   Snipmate and Ultisnips
    +   Better snippets support
    +   Provide advanced completion features

Templates
==============================
+   `0r ~/path/to/template`
+   Reads in a template to new files
+   Can be blocked on file type

Navigating large code bases
==========================
+   Ctags
    +   `^]` go to tag under cursor
    +   `^T` go back to last place
    +   `:tags` show the tag stack
+   Cscope
    +   More powerful but confined to C/C++
    +   Much more intelligent 
    +   Can be configured otherwise, but its hacky

Using vim to Test faster
========================
+   `:make <make_target>`
+   `:set makeprg`
+   `:cn` `:cw` `:cp` `]c` `[c`
+   `:shell`

But Vim does have X feature
===========================
+   It may be a feature
+   Separation of concerns
    +   Uses Cindent for indenting
    +   Uses Ctags for tag management
+   Try Emacs

Wrap-Up
=======

Summary
=======

Further Resources
=================


Questions
=========

Send us feedback at `acm@cs.clemson.edu`!

