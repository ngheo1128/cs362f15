Name: 	Jeff Moss
Date:	11/17/15
Title: 	Documentation of the bugs that were fixed and the code changes.
File:	BugFixes.c
Class:	CS362 Fall 2015

The following bug fixed were implemented:

useSmithy()

Bug:handCount not incremented and decremented correctly.
Fix: Changed logic in useSmithy so that cards being drawn were < 3 rather than <= 3 

discardCard()
Bug: discardCount not incremented correctly. 
Fix: added code to increment discardCount at the end of the function.


