Solutions for Bugs Found By Teammates:
Bug: Smithy Card decreases by 1 card versus decreasing by 2
Solution: Changed food loop from "int i = 0; i > 3; i++" to "int i = 0; i < 3; i++".
Bug: Deck does not decrease in Smithy card function
Solution: Changed food loop from "int i = 0; i > 3; i++" to "int i = 0; i < 3; i++".
Bug: Council Room card increases player's hand count by 1 and not 3
Solution: Changed for loop from "int i = 0; i < 2; i++" to "int i = 0; i < 4 i++".
Bug: 2 treasures are not added with Adventurer card
Solution: Changed while loop from "drawntreasure<3" to "drawntreasure<2".

Solutions for Bugs Introduced in Assignment 2
Bug: For drawAdventurerCard(): while loop was changed from "drawntreasure<2" to "drawntreasure<3".
Solution: Resolved during fix of bugs found by teammates.
Bug: For drawCouncilRoomCard(): for loop was changed from "int i = 0; i < 4; i++" to "int i = 0; i < 2; i++".
Solution: Resolved during fix of bugs found by teammates.
Bug: For drawRemodelCard(): "int j = state->hand[currentPlayer][choice[0]]]" was changed to "int j = state->hand[currentPlayer][choice[1]]]".
Solution: Replaced [choice[1]] with [choice[0]] in j declaration.
Bug: For drawSmithyCard(): for loop was changed from "int i = 0; i < 3; i++" to "int i = 0; i > 3; i++".
Solution: Resolved during fix of bugs found by teammates.