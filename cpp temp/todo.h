#pragma once
/*
KNOWN ERRORS/BUGS

1. After running the get method within the fileStorage() function, the program closes without notice.
	Fix: Flow problem
	Status: Fixed
2. Running through the fileStorage() at the beginning will close the entire program.
	Fix: Flow problem
	Status: Fixed
3. Saying Y to exiting the program (in exitLoop()) will cause the program to restart. (use a char that inputs into an int)
	Fix: Replaced the previous char action2 (with action3), which means navigating to that means saying "n" on the previous action, thereby ignoring the input from the user
	Status: Fixed
4. Need to end program where certain impossible situations can occur:
	4a) User inputs rank for inital and the same for target
		Status: Fixed
	4b) User inputs a rank lower than the inital
		Status: Fixed
	4c) User inputs leftovers that, when added to the inital rank, is greater than the inital rank (overspill)
		Status: Fixed
	4d) User inputs too low of a credit earnings
		Status: Fixed
	4e) User inputs a number that is not a multiple of 5 (credit earnings)
		Status: Fixed
	4f) User inputs a decimal (all functions)
		Status: (Technically) Fixed
	4g) User inputs a negative number (all functions)
		Status: Fixed
	4h) User inputs a calculation that evaluates to violate 4a) to 4g)
		Status: (Technically) Fixed
	4i) User inputs a non-integer (strings, booleans, etc.)
		Status: (Technically) Fixed
5. When prompted to store value, saying "n" or "N" will close the program
	Fix: remove statements that return 0 (returning 0 from a function closes the program)
	Status: Fixed (with option to restart or to exit)
6. Inputting a calculation (on the init char in main()) will temporarily display the number chose that satisfies the proprties
	Example meant is inputting "2-1" which will choose the 2 and only catch the else statement after it displays the credit option menu)
	Fix: ???
	Status: Not Fixed 
7. Setting from the main direction will fail
	Fix: make a separate function that only allows get
	Status: Fixed
8. Storage only allows one value to be stored
	Fix: Maybe push the values done in the run into an array that executes the writing before the program closes
	Status: Fixed
9. CredInit 2 fails the calculation
	Fix: Else statement prevented the for loop from recurring. It is eliminated.
	Status: Fixed
10. File contents get overwritten
	Fix: ("PFRANKTOOL.pfrt", std::ios_base::app)   (Thanks online answers!!!)
	Status: Fixed
*/