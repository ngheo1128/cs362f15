Bugs in mcdokath/dominion.c:
-error in smithyEffect function, line 379, loop runs one too many times in all instances (unittestresults.out, line 202 (in teammate1_dominion))
-error in adventurerEffect function, line 648 or 643, conditional loop on drawnTreasure
allows only 1 treasure card drawn (unittestresults.out, line 221 (in teammate1_dominion))

Bugs in picottes/dominion.c:
-error in smithyCard function, line 669, loop runs one too many times in all instances (unittestresults.out, line 136, in teammate2_dominion)
-error in runAdventurer function, line 663, counter incrementing results in undefined
behavior leading to segmentation fault, should instead be decremented (adventurer random test failed with segfault, bug found with gdb)


