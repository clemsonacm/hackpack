# TODO
I used `--TODO` to make comments on the slides. General suggestions below:

- Include notes on plugins, like plugin managers, what VimL is, and further reading (like vimawesome.com)
- Notes on little-known movement/editing operations, like `caw` (replace a word), `ci(` (replace inside parens)
- Macros would be really useful!
- What the heck is <LEADER> and why is it useful

Introduction to Vim
====================

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

--TODO you're not the VP any more?
Robert Underwood - CS Major\
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
    +   Show you some of the coolest features of vim
    +   Teach you enough to teach yourself

>   Most people use only 10% of the functionality of vim
--TODO source on that statistic?
>   The 10% only differs from person to person

What is Vim?
============

Vim is...
---------
--TODO some of these are sort of redundant/aimless
+   Awesome!
+   A programmer's text editor
+   Very programmable and extensible
+   A tool that is meant to be learned

Vim is NOT
----------
--TODO this section is really vague. I mean, vim _could_ be almost all of your tools, or a word processor (if you're crazy)
+   All of the tools in you tool box
+   A Word Processor

Comparability
=============
--TODO I don't understand what this slide is trying to say.
+   To take elements to make up a whole
+   Actions and Motions
    +   Motions move the cursor
    +   Actions do something
+   combinations of Action and Motion 

Antipatterns
============
--TODO maybe include some numbers on just how important it is to be efficient?
+   A bad way of doing something that becomes habit
    --TODO ddi acts differently than C; ddo is almost the same.
    +   `ddi` instead of `C`

Fixing Some Common Annoyances
=============================
+   Use .vimrc to store preferences --TODO some examples would be useful
+   Turn on the mouse
+   Turn on syntax highlighting
+   Set your background color
+   I hate escape --TODO reasons?
+   Each annoyance has a reason --TODO kind of vague

Copy and Paste
==============
--TODO this slide doesn't seem to offer very practical examples
--TODO there's also quite a lot of content on registers, which I actually don't use all that much.
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
+   `":` last Ex command --TODO "Ex command" might not be obvious
+   `".` last inserted text --TODO Neat, didn't know that!
+   `"%` filename of the current buffer.
+   `"#` filename of the alternate file
    +   More on that in a minute


Multiple Files
==============
+   Use buffers, windows, and tabs --TODO include a quick explanation of what they all are and how they are different from typical view of a window
+   `<C-w>` is prefixes most "window" commands
+   very handy for viewing multiple files
+   argdo, bufdo, tabdo
+   :vsp, :sp, :res :bn :bd :bp
+   :b will change the buffer

Syntax Completion
==============================
+   Syntax Completion
    +   `<C-n>` - Next default completion
    +   `<C-p>` - Previous default completion
+   Omni-completion `<C-x><C-o>` --TODO didn't know about that!
    +   C (limited C++)
    +   CSS, HTML, XHTML, JS
    +   PHP, RUBY

Programming Completion
======================
--TODO Note to self: C-x is REALLY PAINFUL on Dvorak
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

Snippets
==============================
+   Abbreviations will do simple snippets
+   `:ab` create/view abbreviations
+   Snipmate and Ultisnips
    --TODO could use this to segue into plugins
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
    +   `<C-]>` go to tag under cursor
    +   `<C-T>` go back to last place
    +   `:tags` show the tag stack
+   Cscope
    +   More powerful but confined to C/C++
    +   Much more intelligent 
    +   Can be configured otherwise, but its hacky

Using vim to Test faster
========================
--TODO didn't know about most of these!
+   `:make <make_target>`
+   `:set makeprg`
+   `:cn` `:cw` `:cp` `]c` `[c`
+   `:copen`
+   `:shell`

But Vim does have X feature
===========================
--TODO I'm not sure I understand what this slide is saying.
+   It may be a feature
+   Separation of concerns
    +   Uses Cindent for indenting
    +   Uses Ctags for tag management
+   Try Emacs


Further Resources
=================
--TODO include hyperlinks
+   Practical Vim by Drew Neil
+   Vimcasts by Drew Neil
+   vimtips wiki
+   `:help` -- an incredible resource!

Questions
=========

Send us feedback at `acm@cs.clemson.edu`!

