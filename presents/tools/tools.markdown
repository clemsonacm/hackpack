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

	find /etc -user acm -size +2G -mtime -2w

gcc
====
cross compile C, C++, Fortran, Ada, and java (apparently)

+	`-std=standard` adjust the standard used
+	`-c` just compile; don't link
+	`-s` just generate assembly
+	`-g` turn on debug flags
+	`-D` Conditional compilation
+	`<machine>-gcc-<version>` for cross-compilation

gdb
====
Debug C and C++ code

+	accepts format flags for print
+	use the `set` command to force a value
+	can be run in a batch mode `-batch -x script`
+	_warning_ ignores arguments in batch mode

gdb script
==========

	b f
	commands 2
		p x
		p y
		continue
	end

grep
====
Find pattern in a text

+	uses `re_format` style regex
+	`-C3` print 3 lines of context around match	
+	`-c` print number of matches
+	`-e` specify multiple patterns
+	`--exclude` ignore file paths

make
====
Intelligently compile, test, and install

+	variables and functions
+	targets - what is to be built
+	dependencies - what must be built first
+	rules - how to build it	
+	tabs only before rules

makefile example
================

	SRCS=$(wildcard *.cpp)
	all: $(SRCS)
		g++ $(SRCS) -g -Wall
	clean:
		-rm a.out
	test: all
		./a.out

ssh
====
Connect to a remote computer
	
+	`ssh-keygen` create ssh keys
+	`ssh-copy-id user@host` send them to remote machines
+	`-YC` forward X11 compressed
+	takes an optional command argument last

	ssh acm@joey1.cs.clemson.edu ls 

scp
====
Copy files to and from remote locations

+	`-r` recursive
+	`user@location:path`

	scp -r acm@access.cs.clemson.edu:/repos/clemson-acm .


tmux
====
Terminal Multiplexer


sudo
====
Request root privileges

+	`-e filename` edit the file with `$EDITOR`
+	`-g group` run command as group
+	`-u user` run command as user
+	`visudo` edit the sudoers file
+	`user host = (useralias) commandspec`

sudoers file
=============

	#allow root to run all commands
	root ALL=(ALL) ALL
	#allow the admin group to run all commands
	%admin ALL=(ALL) ALL
	#allow acm to reset passwords for all except root
    acm    ALL  = /usr/bin/passwd [A-Za-z]*, !/usr/bin/passwd root
	#allow president to edit the crontab on foobar
	president foobar= sudoedit /etc/crontab


systemctl
=========
Control system processes

+	`start` start a service
+	`stop` stop a service
+	`reload` reload a service
+	`status` get the status of a process
+	`isolate` change target

Systemctl unitfile
==================

	[unit]
		Description=Sample Systemd Unitfile
		Requires=network.target
		After=network.target
	[service]
		Type=oneshot
		RemainAfterExit=yes
		ExecStart=/usr/bin/wpa-supplicant
	[install]
		WantedBy=network.target
		
		

tar
====
Create and extract archives

+	`-c` create archive
+	`-x` extract archive
+	`-j` use bzip2 compression _smaller_
+	`-z` use gzip compressed _faster_
+	`-v` list files as stored/extracted
+	`-f` output file

time
====
time how long it takes a program to execute

+	`time tar -czf foobar`

valgrind
========
A debugger that detects memory leaks

watch
======
repeatedly print the output of a command

+	`-n` Change the update interval
+	`-d` highlight differences
+	`watch -n 1 ls -r`

wget
====
Download file from the Internet

+	`-c` continue the download
+	`-r` recursively download files
+	`-N` only download _new_ files
+	`wget -N www.google.com`

xargs
======
Construct argument lists

+	`-P maxprocs` run commands in parallel	
+	`-s size` limits argument size; default size 4096 bytes
+	`-n number` max number of arguments

	find src/215 -name "*.java"|xargs wc -l

Further Resources
=================
+   [Grymoire](http://www.grymoire.com/)

Questions
=======
Send feedback to acm@cs.clemson.edu

