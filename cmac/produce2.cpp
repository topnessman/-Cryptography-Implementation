#include <stdio.h>
unsigned char PRODUCE2 (unsigned char a)
{
	unsigned char result;
	(a/128)?result=(a*2)^27:result=(a*2);
	 
	return result;
}