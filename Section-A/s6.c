The program crashes when the user leaves the input empty because a pointer-based string traversal may try to
 dereference an invalid or uninitialized pointer. Also, an empty string contains only the null 
 character '\0', so the program must detect the end of the string before accessing its value.

The pointer-based solution should check that the pointer is valid and that the current character is not '\0' before dereferencing it.

Example:
	
	while(ptr != NULL && *ptr != '\0')
{
    printf("%c", *ptr);
    ptr++;
}

Pointer vs Array Index

Pointer traversal:
	
	while(*ptr != '\0')
{
    printf("%c", *ptr);
    ptr++;
}

Array index traversal:
	
	for(i = 0; str[i] != '\0'; i++)
{
    printf("%c", str[i]);
}

Both methods move through the string character by character. Pointer traversal uses *ptr and ptr++, while array traversal uses str[i] and an index.

Array index notation is generally easier for beginners to debug, because str[i] != '\0' clearly shows the check for an empty string/end of string.
	
	
