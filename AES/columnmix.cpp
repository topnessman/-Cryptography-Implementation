#include <stdio.h>
extern unsigned char PRODUCE2 (unsigned char a);
void COLUMNMIX(unsigned char a[4][4])
{
	unsigned char b[4][4];
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			b[i][j]=a[i][j];
	for(j=0;j<4;j++)
		a[0][j]=PRODUCE2(b[0][j])^PRODUCE2(b[1][j])^b[1][j]^b[2][j]^b[3][j];
	for(j=0;j<4;j++)
		a[1][j]=b[0][j]^PRODUCE2(b[1][j])^PRODUCE2(b[2][j])^b[2][j]^b[3][j];
	for(j=0;j<4;j++)
		a[2][j]=b[0][j]^b[1][j]^PRODUCE2(b[2][j])^PRODUCE2(b[3][j])^b[3][j];
	for(j=0;j<4;j++)
		a[3][j]=PRODUCE2(b[0][j])^b[0][j]^b[1][j]^b[2][j]^PRODUCE2(b[3][j]);
}