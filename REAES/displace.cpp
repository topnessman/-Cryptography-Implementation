#include <stdio.h>
void DISPLACE_VERSE(unsigned char a[4][4])
{
	unsigned char t1,t2;
	int i,j;
	t1=a[1][3];a[1][3]=a[1][2];a[1][2]=a[1][1];a[1][1]=a[1][0];a[1][0]=t1;
	t1=a[2][2];t2=a[2][3];a[2][2]=a[2][0];a[2][3]=a[2][1];a[2][0]=t1;a[2][1]=t2;
	t1=a[3][0];a[3][0]=a[3][1];a[3][1]=a[3][2];a[3][2]=a[3][3];a[3][3]=t1;
}