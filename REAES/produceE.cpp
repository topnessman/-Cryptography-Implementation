#include <stdio.h>
extern unsigned char PRODUCE2 (unsigned char a);
unsigned char PRODUCEE (unsigned char a)
{
	unsigned char result;
	result=PRODUCE2(PRODUCE2(PRODUCE2(a)))^PRODUCE2(PRODUCE2(a))^PRODUCE2(a);
	return result;

}