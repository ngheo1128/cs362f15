/*
One of my teammates was able to find the bug I introduced to the
Smithy implementation and another was able to find a bug that I 
didn't implement into the Adventurer card. I've tried debugging 
but have been unable to find the bug reported by my teammate.

############
Adventurer
############
Bugs in Toro
Bug 1 
Adventurer Card does not increase handsize
where 
AdventurerCard function
description
The adventurer card does not cause hand size to increase by 1 as it should



#######
Smithy
#######
Title: Playing smithy card results in an incorrect action count.
Where:
	smithyCard() in the dominion.c file.
Bug Description:
	The expected action count after the smithy card code is executed is 1,
	but the actual action count is 2. This means the smithy card is adding 
	actions when it isn't supposed to.

BUG Fix:
	To fix the bug I introduced, I got rid of the if statement that checked
	if the card drawn was gold, then the number of actions for the player
	would be increased by 1.
	
#########