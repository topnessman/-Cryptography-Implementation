#include <stdio.h>
extern unsigned char PRODUCEE (unsigned char a);
extern unsigned char PRODUCEB (unsigned char a);
extern unsigned char PRODUCED (unsigned char a);
extern unsigned char PRODUCE9 (unsigned char a);
void COLUMNMIX_VERSE(unsigned char a[4][4])
{
	unsigned char b[4][4];
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			b[i][j]=a[i][j];
	for(j=0;j<4;j++)
		a[0][j]=PRODUCEE(b[0][j])^PRODUCEB(b[1][j])^PRODUCED(b[2][j])^PRODUCE9(b[3][j]);
	for(j=0;j<4;j++)
		a[1][j]=PRODUCE9(b[0][j])^PRODUCEE(b[1][j])^PRODUCEB(b[2][j])^PRODUCED(b[3][j]);
	for(j=0;j<4;j++)
		a[2][j]=PRODUCED(b[0][j])^PRODUCE9(b[1][j])^PRODUCEE(b[2][j])^PRODUCEB(b[3][j]);
	for(j=0;j<4;j++)
		a[3][j]=PRODUCEB(b[0][j])^PRODUCED(b[1][j])^PRODUCE9(b[2][j])^PRODUCEE(b[3][j]);
}