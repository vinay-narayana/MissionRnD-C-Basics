/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int validate(int day, int month, int year)
{
	int range[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0)
		range[1] = 29;
	if ((month > 0 && month <= 12) && (day <= range[month - 1]))
		return 1;
	else
		return 0;
}

int isOlder(char *dob1, char *dob2)
{
	int i, j, day = 0, month = 0, year = 0, day1 = 0, month1 = 0, year1 = 0, v1, v2;
	for (i = 0; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		day = (day * 10) + dob1[i] - '0';
		day1 = (day1 * 10) + dob2[i] - '0';
	}
	i++;
	for (j = i; dob1[j] >= '0' && dob1[j] <= '9'; j++)
	{
		month = (month * 10) + dob1[j] - '0';
		month1 = (month1 * 10) + dob2[j] - '0';
	}
	j++;
	for (i = j; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		year = (year * 10) + dob1[i] - '0';
		year1 = (year1 * 10) + dob2[i] - '0';
	}
	v1 = validate(day, month, year);
	v2 = validate(day1, month1, year1);
	if (v1 == 0 || v2 == 0)
		return -1;
	else if (year<year1)
		return 1;
	else if (year1 < year)
		return 2;
	else if (month < month1)
		return 1;
	else if (month1 < month)
		return 2;
	else if (day < day1)
		return 1;
	else if (day1 < day)
		return 2;
	else
		return 0;
}

