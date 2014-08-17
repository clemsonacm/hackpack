Linux 101
=========

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

Joshua Hull - Chief Presenter\
 Austin Anderson - ACM President

Coming up
=========

1.  What's up with Linux?
2.  The linux file system
3.  Terminal Power
4.  Getting owned by Permissions
5.  Working from Other Machines
6.  Your free webhosting at people.cs.clemson.edu
7.  Wrap-up

What's up with Linux?
=====================

Linux: A Short History
======================

-   Created in 1991 by **Linus Torvalds**
-   Written in C and Assembly
-   Uses a *Unix-like* file structure (more on that later)
-   Kernel is still being maintained by Torvalds & open source
    contributors
-   You could contribute if you wanted!

What's a Distribution?
======================

-   A "flavor" of Linux with small differences from the others
-   **All** have many similarities
-   Might differ in...
    -   *Desktop Environment*, the set of programs that handle... the
        desktop
        -   Examples are **Gnome** and **KDE**
    -   *Package manager*
    -   Default *applications*
    -   Behind-the-scenes *settings*

Common Distributions
====================
-   Some common distributions are Ubuntu (and children Xubuntu,
    Kubuntu), Fedora, Debian, and Arch Linux (not for the faint of
    heart) -- you configure *everything*

Big Names in \*nix
==================

-   **Linus Torvalds** - creator of Linux, *extremely passionate*.
-   GNU Project - "GNU's Not Unix", connected to open source software
    licensing (like the GNU Public License, or GPL)
-   Greg Kroah-Hartman: Linux Kernel maintainer and all around awesome
    dude.

"Kernel" and Other Scary Words
==============================

-   **Kernel** is the part of Linux that interacts with your PC's
    hardware.
-   **Shell** refers to the program that handles your terminal
    environment with things like the *prompt* and coloring.
-   **Bash** is the default shell.

"Kernel" and Other Scary Words
==============================
-   **Grub** is a common Linux *boot manager* that remembers how to get
    from turning your computer on into the OS.
-   **PATH** is an *environment variable* that remembers where to look
    for executables when you type one in the terminal

"Kernel" and Other Scary Words
==============================
-   **Version control systems** like **Git**, **SVN**, and **Mercurial**
    allow you to easily implement histories of a project. Linux uses
    Git!
    -   Web handin uses Mercurial as a backend and provides a tutorial
        for connecting to Handin on your machine
-   **`make` and `Makefile`s** are a *build system* that allow you to
    define rules for running multiple commands at once. Very useful for
    compiling code.

"Building from Source"
======================

-   When you can't get a pre-compiled executable
-   Download the source code and run...
-   `./configure`
-   `make`
-   `sudo make install`
-   Didn't work? Read README

Packaging systems
=================

-   Easy way to install many applications pre-configured for your OS
-   Different distributions have their own **Package Managers**
    -   All package managers need to be run using `sudo`
    -   `apt-get` - used on Debian based system, including Ubuntu.
        -   `apt-get update` - update metadata
        -   `apt-cache search <package>` - find package
        -   `apt-get install <package>` - install package
        -   `apt-get dist-upgrade` - update all packages

Other Packaging systems
========================
-   `yum` - used on Red Hat based system, including Fedora
-   `pacman` - used on Arch Linux
-   `rpm` - Legacy back end that is compatible with yum

The Linux File System
=====================

Basic Hierarchy
===============

-   Based on *one* root directory, not drives like C: or D:
-   Physical devices (drives, output) and important folders are
    *mounted* to subdirectories of `/`
    -   `/home` - where user's files normally live
    -   `/dev` - device nodes. Don't mess with things here.
    -   `/mnt` - where you can mount things like USB drives.
    -   `/usr` - where system libraries and the like are.
    -   `/bin` - stores system executables

    **Some distros are a little different in how they manage these folders.**

Everything is a File
====================

-   Linux sees every object as a subclass of a file.
-   Folders, links, output devices, executables are all "files"!

Where are my .exes?
===================

-   File extensions categorize, not restrict
-   A file with any name could be executed
    -   `a.out`, `prog1`, `.bashrc`
-   Files starting with a dot like `.bashrc` are usually *hidden* from
    listings
-   Running a command like `sl` is really just running an executable
    file within the PATH

Terminal Power
==============

echo "Simple navigation commands"
=================================

-   Stuck? `Ctrl+c` force quits the running program.
-   `pwd` lists your current directory
-   `cd directory` moves the terminal to `directory`
-   `ls` lists files and folders in the current directory
    -   `ls -l` gives additional file information
    -   `ls -a` shows even `.hidden-files`

echo "Simple navigation commands"
=================================

THERE IS NO TRASHCAN. DELETION IS PERMANENT.
--------------------------------------------

-   `mv orig.file new.file` moves `orig.file` to `new.file`
    -   Use this for moving and **renaming**!
-   `cp orig.file clone.file` copies `orig.file` to `clone.file`
-   `rm file` removes a file
    -   `rm -r directory` deletes a directory

--Flags?! : Command Structure
=============================

-   Generally
    `command -one-letter-flag --longer-flag parameter`
    `[optional parameter] parameter-list...`
-   Some flags need their own value arguments after them
    -   `ping -c 12` OR `ping --count=12`
-   Structure varies by program: try `progname --help` or `-h` 
    -   Sometimes simpler than `man progname`
-   Many commands use `--verbose` or `-v` to print *more* useful
    information. Verbosity is good!

Terminal Symbols & Shorthand
============================

-   `.` (one dot) is the *current directory*
-   `..` (two dots) is the *parent directory*
-   `/` is the *root directory*
-   `~` is your *user directory*
-   `!!` is the *previously entered command*
    -   Use `sudo !!` to run the last command under sudo

Terminal Symbols & Shorthand
============================

-   `\` begins an escape character sequence
    -   `\n` is a newline character
    -   `\` (space) inserts a space into one argument (otherwise the
        argument will break)
    -   `\\` actually inserts a backslash
    -   `$(command)` or `command` inserts the output of `command` into
    -   `command&` will run `command` in the background

Messing with Output
===================

-   Any text output you see in the terminal comes from **standard out**
    (the same stream as **cout** in C++ and **printf()** in C)
    -   `echo input` - print `input` to standard out
    -   `cat input.file` - print contents of `file` to the terminal
-   Many commands like `grep` and `less` read from **standard in**
    (**cin** in C++, what **scanf()** reads from in C) if no other args
    are specified
    -   `grep pattern input.file` prints lines from `input.file` that
        match/contain the search pattern (could be as simple as one
        word)
    -   `less input.file` allows you to read up and down through a large
        chunk of data

Piping and Redirection
======================

-   **Piping** with `command-a | command-b` connects the *standard
    output* of `command-a` to *standard input* of `command-b`, for
    chaining commands
    -   `command-a | less` pipes `command-a`'s output into less for easy
        reading
-   **Redirection** handles using file contents for standard in / out
-   `progname > output.file` overwrites `output.file` with `progname`'s
    output

Redirection
===========
-   `>>` *appends to* `output.file` with `progname`'s output
-   `&>` overwrites `output.file` with `progname`'s *error output*
-   `&>>` *appends to* `output.file` with `progname`'s *error
    output*
-   `progname < input.file` uses `input.file`'s content as input for
    `progname`

Shell History
=============

"How did I run that again?"
---------------------------

-   Press the up key to cycle through your previously entered commands
-   `history` - print previous commands
-   Try it with grep -- `history | grep ls`
-   `ctrl-r` for a history search

Shell configuration
===================

-   On your home machine, you could replace **bash** with another shell
    like **zsh** or **ksh**
-   Editing `~/.bashrc` can customize your shell with functions,
    **aliases**, and **functions**.
-   Aliases are simple: `alias sl=echo "Steam Locomotive"`
-   There are a ton of tutorials on customizing the shell, so we'll skip
    it for now.

`man` and Other Awesome Commands
================================

-   `man` - summons an *extensive* manual page for about anything
    -   `man stdio.h`, `man grep`, `man man`
-   `sl` summons a steam locomotive!
-   `touch name.file` creates an empty `name.file` if none exists
-   `vim [edit.file]` awesome text editor with steep learning curve
-   `nano [edit.file]` opens a simple editor
-   `curl -O [URL]` copies a file from the web


`man` and Other Awesome Commands
================================

-   `tar` - manage tarball (.tar) and tarball + gzipped (.tgz, .tar.gz)
    archives
    -   `tar -xzf` (e**x**tract **z**e **f**iles!!) `<archive>`
        -   `tar -xf` for just `.tar`
    -   `tar -czf` (**c**reate **z**e **f**iles!!)
        `archivename.tgz files...` to create an archive
    -   [Relevant XKCD comic](http://imgs.xkcd.com/comics/tar.png)

Shell Scripts
=============

-   put commands into a file to run them all at once repeatidly
-   add `#!/bin/bash` as the first line
-   one command per line
-   `chmod u+x script.sh`
-   `./script.sh`

Getting Owned by Permissions
============================

Users, Root and Groups
======================

-   *Users* are unique accounts
-   *Root* is the **superuser** and can do *anything*.
    -   **DON'T TRY TO USE ROOT ON THE CU MACHINES**.
    -   Run one command as root with `sudo <command>` and temporarily
        login with `sudo su`
-   Users in the same *Groups* share permissions pertaining to that
    group
    -   E.g. users in `sudoers` can use `sudo` (the admin group might be
        different on other distros)
    -   Users can be in multiple groups
-   `man chmod` and `man chgrp` for more info on permissions and groups

Working from other machines
===========================

Getting to your files with SSH
==============================

-   `ssh username@access.cs.clemson.edu` starts a remote connection to
    the Lab computer
-   Pick one of the servers listed in the message and `ssh` to it
-   **DON'T RUN/COMPILE ON access.cs.clemson.edu**

Using a VM
==========

-   VirtualBox
    -   Can run a Linux VM inside of Windows/Mac OS X

Windows: Cygwin?
================

**Bad Idea.**
-------------

Your Free Clemson Web Hosting
=============================

-   Run `cd /web/home/username/public_html`
    -   Trust us, it's there
-   Files you put there will be served on the web at
    `people.cs.clemson.edu/~username/`
-   Change permissions so the web server can access them
    -   `chmod a+r [serving files]`
    -   `chmod a+g [sub-directories]`

Wrap-up
=======

Final warnings
==============

NEVER RUN A RANDOM COMMAND FROM THE INTERNET
--------------------------------------------

-   **DON'T CHEAT**
    -   Professors use advanced software that checks the algorithms your
        code uses
    -   Changing variable names won't help
-   Don't use `sudo` on the lab machines
    -   They yell at you and phone home to the sysadmins
-   Want to install something? Email `ithelp@clmeson.edu` and put
    `School of Computing` in the subject line.

The snapshot system
===================

-   Contents are in `~/.snapshot`
-   Keeps hourly, nightly, and weekly backups of files in `~`
-   Especially useful when you accidentally overwrite a project at 2 am

    SNAPSHOTS ARE UNIQUE TO CLEMSON. DON'T RELY ON IT!
    --------------------------------------------------

Further resources
=================

-   `http://www.cs.clemson.edu/help/linux-workshop/soc_linux_cheatsheet.pdf`
    -- the cheatsheet we're distributing
-   `http://www.cs.clemson.edu/help/linux-workshop`
    -   Steps to install a VM just like the lab machines
    -   submit/handin information is deprecated
-   Plug a long command into
    [ExplainShell.com](http://explainshell.com/) to see what it does
-   We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
    [Facebook](https://www.facebook.com/groups/283823058297107/)!
-   Lists system admin staff

Questions
=========

Send us feedback at `acm@cs.clemson.edu`!
