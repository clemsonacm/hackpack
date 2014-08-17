Git 101
=======

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

Robert Underwood - CS Major\
 Austin Anderson - ACM President

Coming Up
=========
1.  Unpleasant and contemptible people in cs.
2.  Why on Earth do I care?
3.  How you can *git* started?
4.  Wrap-up

Unpleasant People
=====================

-   git - (n) An unpleasant or contemptible person.
    -   Not something we generally like
    -   For example that git in McAdams that never bathes
    -   [Oxford English Dictionary](http://www.oxforddictionaries.com/us/definition/english/git)
-   git - (n) Free, Open Source, Fast, Scalable, and Distributed Version Control System
    -   Free as in lunch
    -   Open Source as in Linux
    -   Distributed Version Control System??

DCVS and Why You Should Care
============================
-   Imagine the following...

Version Control Iteration 1 (Manual)
=====================================
-   Create a file 
-   Save several copies
-   Opps, we overwrote our backup ...


Oh, What about Austin?
===========================
-   Two people working on the project
-   `diff` and `patch`
-   What if Daniel joins the team?
-   What about reversion?


Version Control Iteration 2 (CVS)
=================================
-   Send files to a central location
-   Keep a copy of each version of a file
-   Keep track of some meta data
-   Programmaticly control reversion
-   Now 50 people join the team...


Ok, What about Austin Now?
===========================
-   What if Daniel Joins the team?
-   What about reversion?
-   What happens if the server dies?
-   What if we want to branch out?

Version Control Iteration 3
===========================
-   Each programmer keeps a copy of the repo
-   Programmers `merge` their copies of the repo
-   Store branches as diffs of past code
-   Now were *gitting* somewhere
    - see what we did there...

Ok, What about Austin Now?
===========================
-   What if Daniel Joins the team?
-   What about reversion?
-   What happens if the server dies?
-   What if we want to branch out?

Getting Started with git
========================
-   First, `git config --global`:
    -   user.name   "Mr. President"
    -   user.email acm@clemson.edu
    -   core.editor vim
    -   color.ui
-   `git init`


Adding some files
=================
-   `git add`
-   `git status`
-   `git commit`

Ok... What just happend?
========================
-   `git log`
-   `git diff`
-   `git blame`

Opps...
=======
-   `git checkout --`
-   `git revert`
-   As a last resort `git reset HEAD --hard`

What is Master?
===============
-   One Branch to rule them all??
-   Stable, Final, Sharable Product
-   Try not to make changes directly here
-   **Always** test changes merged into Master

Because Branches
================
-   `git branch`
-   `git checkout -b MyNewBranch`
-   `git merge MyNewBranch`

Sharing code
============
-   GitHub and Bitbucket offer free "hosts" 
-   Fairly easy to set up a git "server"
-   `git remote add origin`
-   `git push -u MyNewBranch`

Downloading Code
================
-   `git clone`
-   `git pull`

Merge Conflicts
==============
-   `git mergetool`
-   There are also tools to do this better
-   Often fairly painless
-   Don't forget to retest after merges

Need more power?
================
-   Some hosts provides wikis and issue trackers
-   Pull Requests as a code review tool
-   Git provides hooks for automating tasks
-   vim Fugitive
-   `git help`

But my lovely UI... :(
======================
-   There are tools that use git with GUIs
-   Some of them are quite good
-   Meld is fantastic, but there are others
    -   Downside is Meld is not on lab machines
    -   gvimdiff and vimdiff for the vim crowd
    -   For the emacs OS use `emerge`


Wrap-Up
=======

Summary
=======
-   Please use version control
-   Git is an easy to use DCVS
-   Spend less time reverting more time coding

Further Resources
=================
-   [Cheatsheet](https://www.atlassian.com/dms/wac/images/landing/git/atlassian_git_cheatsheet.pdf)
-   [Workflows](https://www.atlassian.com/git/workflows)
-   [Mecurial (hg)](http://blogs.atlassian.com/2012/02/mercurial-vs-git-why-mercurial/?utm_source=wac-dvcs&utm_medium=text&utm_content=dvcs-options-git-or-mercurial)


Questions
=========

Send us feedback at `acm@cs.clemson.edu`!

