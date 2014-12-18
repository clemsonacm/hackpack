N tools in O(N) minutes
=======================

### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[Facebook](https://www.facebook.com/groups/283823058297107/)!

### Speakers:

Robert Underwood - ACM Vice President\
 Austin Anderson - ACM President

Coming Up
=========
+	For each tool:
	+	Purpose
	+	common use cases
	+	important flags
	+   alternatives

awk
====
pattern scanning and processing

+	`BEGIN {action}` executes before processing
+	`pattern {action}` default pattern style
+	`END {action}` executes after the file is processed
+	patterns are based on `re_format`
+	missing patterns always match, missing actions always print

example awk script
==================

	#computes the average of space delimited data
	#where the second column is even
	BEGIN {n = 0}
	$2%2 == 0 {s += $1; n++}
	END {print "sum is", s, " average is", s/n}

bash
====
gluing programs together

+	`|` pipelining
+	`&> dest` redirect stderr and stdout to dest
+	`word` executes word in a subshell first
+	support `for` and `while` loops

example bash script
===================

	for i in `ls`
	do
	cd $i
	git pull
	cd ..
	done


cron
====
running jobs at fixed times

+	Probably the least standardized tool on this list
+	On most modern linux boxes replaced by systemd
+	`crontab -e` edit user crontab
+	persistent crontab; system dependent location
+	_warning_ cron ignores _all_ environment variables

example crontab
===============

	PATH=/usr/bin
	SHELL=/bin/bash
	MAILTO=acm
	# minute hour dayOfMonth month dayOfWeek cmd
	0 0 0 * * echo "Cron Example"

find
====
find files on the file system

+	can be filtered by user, size, time, name
+	can be used to preform batch operations

gcc
====
compile C, C++, Fortran, Ada, and java (apparently)

gdb
====
Debug C and C++ code

grep
====
Find pattern in a text

make
====
Intelligently compile, test, and test

scp
====
Copy files to and from remote locations

tmux
====
Terminal Multiplexer

ssh
====
Connect to a remote computer

sudo
====
Request root privileges

systemctl
====
Control system processes

tar
====
Create and extract archives

time
====
time how long it takes a program to execute

valgrind
========
A debugger that detects memory leaks

watch
======
repeatedly print the output of a command

wget
====
Download file from the Internet


wget example
============


xargs
======

Further Resources
=================
+   [Grymoire](http://www.grymoire.com/)

Questions
=======
Send feedback to acm@cs.clemson.edu

