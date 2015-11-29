Changed all "playXXXX" functions to previous version 
	this previous version is the one that was saved on computer locally.
	also notable, this was a source of the problems for Assignment 3
	
Note, GDB is still a bit confusing
	but to be fair, most of the commands for gcov are still confusing.
	They are only less confusing now that I've used them more and retyped teh commands 
		in the makefile numerous times and reviewed what I was doing each time.
		
commands used:
	GDB	XXXX	// initializer XXX is an executable
	break YYYY	// stop after function YYYY is met
	run			// execute XXXX
	
	program runs
	
	bt			// backtrace
	print state	// pointer has no information
	watch ZZZZZ	// backtrace watches that memory location (ZZZZ is a variable)
	continue	// continue execution
	
	After a several tests, this was understood better
	*note* debugging of this sort was more confusing than using "printf"
	
**note** I think i know know what was going on.
	Playedhand -> cards that have been played during turn, but not yet discarded.
	