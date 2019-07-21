#include <ctype.h>
#include <string.h>
#include <stdio.h>

//checking that input contains 2 string with digits only
int checkstr(char *str)
{
    for (int i = 0; i< strlen(str); i++)

         if (!isdigit(str[i]))

         return 0;

    return 1;
}

int check_input(int arc, char **arg)
{
     if (arc < 3 || arc >= 4)
    {
		puts("Please Provide Two Unsigned Integers as arguments");
		return 1;
	}

    if (checkstr(arg[1]) == 0 || checkstr(arg[2]) == 0 )
    {
		puts("Wrong Data - Please Provide Only Unsigned Integers as arguments");
		return 1;
	}

	return 0;
}
