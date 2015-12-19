#include <stdio.h>
extern unsigned char PRODUCE2 (unsigned char a);
unsigned char PRODUCEB (unsigned char a)
{
	unsigned char result;
	result=PRODUCE2(PRODUCE2(PRODUCE2(a)))^PRODUCE2(a)^a;
	return result;

}