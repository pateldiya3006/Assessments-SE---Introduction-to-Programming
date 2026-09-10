An array is the correct data structure because it can store all 30 rainfall readings under one variable and allows 
us to access each day's reading using an index. Using 30 separate variables would make the program longer, harder to manage, 
and difficult to process with loops.

For example:
	float rainfall[30];
	
Two-Step Logic

Step 1: Calculate the monthly average

Store rainfall for all 30 days in the array.
Add all 30 readings using a loop.
Divide the total by 30 to get the average.

Step 2: Find above-average days

Use another loop to check each day's rainfall.
If rainfall[i] > average, print that day as an above-average rainfall day.
Why two loops?

Both steps cannot normally be done in a single loop because the average is not known until all 30 rainfall readings have been processed. We need the calculated average first, and only then can we compare each day's rainfall with it.

Therefore:
First loop ? Calculate average
Second loop ? Find above-average days
