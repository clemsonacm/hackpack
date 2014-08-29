Git 101
=======

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

Robert Underwood - ACM Vice President\
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

What is DVCS and Why You Should Care
====================================
-   Imagine the following...

What you are probably doing right now
=====================================
-   Create a file 
-   Save several copies (with different names?)
-   Oops, we overwrote our backup ...

And what about group projects?
===============================
-   Emailing versions back and forth
-   `diff` and `patch`
-   What if you screwed up?
-   What if a new group member joins?

Now version control makes us happy :)
=====================================
-   Store a file to a repository
-   The software tracks the versions
-   New team members checkout/clone the repo
-   Now were *gitting* somewhere
    - see what we did there...

Getting Started with git
========================
-   First, `git config --global`:
    -   user.name   "Mr. President"
    -   user.email acm@clemson.edu
    -   core.editor Vim
    -   color.ui True
-   `git init` - creates a new repo
-   `git clone`

Adding some files
=================
-   `git add` - staging new changes
-   `git status` - see the current status
-   `git commit` - Saves a 'set' of version

Ok... What just happened?
========================
-   `git log` - See what you did
-   `git diff` - See the actual changes
-   `git blame` - See when a line was last changed

Oops... Now what??
=================
-   `git checkout --` to reset to last commit
-   `git revert` - to reset to a specific commit
    -   try not to use `git reset` ever
-   As a last resort `git reset HEAD --hard`


What is a branch?
================
-   A branch is a set of related versions
-   Great for
    -   Trying something new 
    -   Building new features 
    -   Toss it or Merge it

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
-   `git push` after the first push

When sharing is not caring
==========================
-   Some files should not be shared
    -   May contain sensitive information
    -   May be machine/developer specific
    -   May be a breach of academic integrity
-   Use a `.gitignore` or `core.excludes` file

Merge Conflicts
==============
-   `git mergetool`
-   There are also tools to do this better
-   Often fairly painless
-   Don't forget to retest after merges

Need more power?
================
-   Some hosts provide wikis and issue trackers
-   Pull Requests are a great code review tool
-   Git provides hooks for automating tasks
-   vim Fugitive
-   `git help`

But my lovely UI... :(
======================
-   There are tools that use git with GUIs
-   Some of them are quite good
    -   Github has a great desktop client
-   Meld is fantastic, but there are others
    -   Downside is Meld is not on lab machines
    -   gvimdiff and vimdiff for the Vim crowd
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
-   [Great Book](http://git-scm.com/book)
-   [Cheatsheet](https://www.atlassian.com/dms/wac/images/landing/git/atlassian_git_cheatsheet.pdf)
-   [Workflows](https://www.atlassian.com/git/workflows)
-   [Mecurial (hg)](http://blogs.atlassian.com/2012/02/mercurial-vs-git-why-mercurial/?utm_source=wac-dvcs&utm_medium=text&utm_content=dvcs-options-git-or-mercurial)


Questions
=========

Send us feedback at `acm@cs.clemson.edu`!

