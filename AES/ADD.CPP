#include <stdio.h>
void ADD(unsigned char a[4][4],unsigned char b[4][4])
{
	int i,j;
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
			a[i][j]=a[i][j]^b[i][j];
}